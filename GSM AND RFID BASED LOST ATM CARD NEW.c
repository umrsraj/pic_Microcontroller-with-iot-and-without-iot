/*
GSM AND RFID BASED LOST ATM CARD NEW

PIC16F877A
LCD= B PORT
RFID= A0,
GSM=B0,B1,
C0 = BUTTON,

D3 = BUZZER,

D2,D3= G AND R LED'S

*/

#include <16F877A.h>           //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use     delay(clock=20M)          // operating Clock freequency
#use     rs232  (baud = 9600, rcv=PIN_B1, xmit=PIN_B0,stream=GSM)
#use     rs232  (baud = 9600, rcv=PIN_A0,stream=RFID)
#include "flex_lcd.c"

//WELCOME MESSAGE SENDING
void send_sms1()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9542924310\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM," KIT STARTED..\r\n");
delay_ms(1000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
}

//1ST PERSON NUMBER
void send_sms2()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9542924310\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"YOUR ATM USED AT DSNR AXIS ATM. PLEASE CHECK.....\r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
}
void send_sms3()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9542924310\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"Thank you for using DSNR AXIS ATM\r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
}

void show_projectname()
{
      lcd_putc('\f');
      lcd_gotoxy(4,1);
      printf(lcd_putc,"GSM AND RFID ");
      lcd_gotoxy(4,2);
      printf(lcd_putc," BASED LOST  ");
      delay_ms(2000);
      lcd_putc('\f');
      lcd_gotoxy(4,1);
      printf(lcd_putc,"ATM CARD ");
      lcd_gotoxy(0,2);
      printf(lcd_putc,"-----------------");
      delay_ms(2000);
      
}

void beep()
{
output_high(pin_d1);
delay_ms(1000);
output_low(pin_d1);
}

int16 i;
char value[12];//12 values of tag ID


void main() 
{ 
    
   lcd_init(); 
  show_projectname();


 //HEALTH CHECK UP
output_high(pin_d2);  //GREEN LED
output_high(pin_d3);  //RED LED
delay_ms(1000);
output_low(pin_d2); //GREEN LED OFF
output_low(pin_d3); //RED LED OFF
delay_ms(1000);
output_high(pin_d2);  //GREEN LED
output_high(pin_d3);  //RED LED
delay_ms(1000);
output_low(pin_d2); //GREEN LED OFF
output_low(pin_d3); //RED LED OFF
delay_ms(1000);

send_sms1();
y:
     lcd_putc('\f');
      lcd_gotoxy(1,1);
      printf(lcd_putc,"PLEASE INSERT CARD");
      lcd_gotoxy(0,2);
      printf(lcd_putc,"WELCOME TO AXIS BK");
      delay_ms(2000);
  
   
  while (1)
  {
    
  if(!input(pin_C0)||(!input(pin_D7)))
  {
   output_high(pin_d2);  //GREEN LED
  for (i=0; i<12; i++) 
     { 
       value[i]=getc(RFID);
     }
    
    
     if(value[7]=='E' && value[8]=='E' && value[9]=='8' )//19004AEDCC72
     {
    output_high(pin_d2);  //GREEN LED
     lcd_putc('\f');
     
     lcd_gotoxy(1,1);
     printf(lcd_putc,"Number=%s", value);
     lcd_gotoxy(1,2);
     printf(lcd_putc,"  Thank you    ");
     delay_ms(2000);
     
     lcd_putc('\f');     
     lcd_gotoxy(1,1);
     printf(lcd_putc,"For using DSNR");
     lcd_gotoxy(1,2);
     printf(lcd_putc," AXIS BANK ATM");
     delay_ms(2000);
     
     send_sms3();
     output_low(pin_d2);  //GREEN LED OFF
      lcd_putc('\f');
      lcd_gotoxy(1,1);
      printf(lcd_putc,"PLEASE INSERT CARD");
      lcd_gotoxy(0,2);
      printf(lcd_putc,"WELCOME TO AXIS BK");
      delay_ms(1000);
     }
     
  //invalid card
  else
  {   output_high(pin_d3); output_low(pin_d2);
       lcd_putc('\f');
      lcd_gotoxy(0,1);
      printf(lcd_putc,"INVALID ARM CARD");
      lcd_gotoxy(0,2);
      printf(lcd_putc,"PLEASE CHECK.....");
      beep();
      delay_ms(1000);
      goto y;
   
  }//else
   }  //rfid
   
   
  else
  {
 // output_low(pin_d2);  //GREEN LED
  for (i=0; i<6; i++) 
     { 
       value[i]=getc(RFID);
     }
        
     if(value[7]=='E' && value[8]=='E' && value[9]=='8' )//19004AEDCC72
     {
      output_high(pin_d3);  //RED LED ON
      output_high(pin_d1);  //RED LED ON
      lcd_putc('\f');
      lcd_gotoxy(1,1);
      printf(lcd_putc,"YOU ARE THEFT");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"  THIS CARD  ");
      delay_ms(2000);
      send_sms2();
      output_low(pin_d3);  //GREEN LED OFF
      output_low(pin_d1);  //GREEN LED OFF
       lcd_putc('\f');
      lcd_gotoxy(1,1);
      printf(lcd_putc,"PLEASE INSERT CARD");
      lcd_gotoxy(0,2);
      printf(lcd_putc,"WELCOME TO AXIS BK");
      delay_ms(1000);
     }
     
      
  //invalid card
  else
  {   output_high(pin_d3); output_low(pin_d2);
       lcd_putc('\f');
      lcd_gotoxy(0,1);
      printf(lcd_putc,"INVALID ARM CARD");
      lcd_gotoxy(0,2);
      printf(lcd_putc,"PLEASE CHECK.....");
      beep();
      delay_ms(1000);
       goto y;
   
  }//else  
     
  }
  
  }//WHILE
  
    
}//MAIN



