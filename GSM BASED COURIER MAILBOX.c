/*
GSM BASED COURIER MAIL BOX

PIC16F877A
LCD= B PORT

A0 = IR SENSOR 1  AT BOTTOM,
A1= IR SENSOR 2 AT TOP,

GSM=B0,B1,
D1 = BUZZER,
D2,D3= G AND R LED'S

*/

#include <16F877A.h>           //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use     delay(clock=20M)          // operating Clock freequency
#use     rs232  (baud = 9600, rcv=PIN_B1, xmit=PIN_B0,stream=GSM)
#include "flex_lcd.c"

//WELCOME MESSAGE SENDING
void send_sms1()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"7095283934\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM," WELCOME!! COURIER MAILBOX.\r\n");
delay_ms(1000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 

//2 ND MESSAGE
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"7207522449\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM," WELCOME!! COURIER MAILBOX.\r\n");
delay_ms(1000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 

//3RD MESSAGE
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"7382385422\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM," WELCOME!! COURIER MAILBOX.\r\n");
delay_ms(1000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 
}


//2ND  lower sensor
void send_sms2()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"7095283934\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"YOU HAVE RECEIVED COURIER**PLS Check***\r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(5000); 

//2nd message
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"7207522449\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"YOU HAVE RECEIVED COURIER**PLS Check***\r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(5000);


//3rd message
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"7382385422\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"YOU HAVE RECEIVED COURIER**PLS Check***\r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(5000);
}

// upper sensor courier FULL
void send_sms3()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"7095283934\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM," YOUR LETTER BOX = FULL**PLS Check***\r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(5000); 

//2nd message
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"7207522449\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM," YOUR LETTER BOX = FULL**PLS Check***\r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(5000);


//3rd message
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"7382385422\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM," YOUR LETTER BOX = FULL**PLS Check***\r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(5000);
}




void show_projectname()
{
      lcd_putc('\f');
      lcd_gotoxy(1,1);
      printf(lcd_putc,"ALERTING COURIER ");
      lcd_gotoxy(2,2);
      printf(lcd_putc," MAILBOX SYTEM ");
      delay_ms(2000);
     
}

void beep()
{
output_high(pin_d1);
delay_ms(1000);
output_low(pin_d1);
}

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
delay_ms(5000);
  
   
  while (1)
  {
  //COURIER MAIL BOX FULL  
  if(input(pin_A0)&&(input(pin_A1)))
  {
   output_low(pin_d2);  output_high(pin_d3);  //GREEN LED    
    beep();         
     lcd_putc('\f');     
     lcd_gotoxy(1,1);
     printf(lcd_putc,"COURIER MAILBOX");
     lcd_gotoxy(1,2);
     printf(lcd_putc,"STATUS : FULL ");
     delay_ms(2000);
         
         lcd_putc('\f');     
     lcd_gotoxy(1,1);
     printf(lcd_putc,"SMS SENDING......");
     lcd_gotoxy(1,2);
     printf(lcd_putc,"STATUS : FULL ");
     delay_ms(2000);
     send_sms3();
     lcd_putc('\f');     
     lcd_gotoxy(4,1);
     printf(lcd_putc,"SMS SENT");
     lcd_gotoxy(1,2);
     printf(lcd_putc,"STATUS : FULL ");
     delay_ms(2000);
     }
     
 
  //COURIER FULL
  if(input(pin_A0)&&(input(pin_A1)))
  {
   output_low(pin_d2);  output_high(pin_d3);  //GREEN LED    
    beep();         
     lcd_putc('\f');     
     lcd_gotoxy(1,1);
     printf(lcd_putc,"COURIER MAILBOX");
     lcd_gotoxy(1,2);
     printf(lcd_putc,"STATUS : FULL ");
     delay_ms(2000);
         
         lcd_putc('\f');     
     lcd_gotoxy(1,1);
     printf(lcd_putc,"SMS SENDING......");
     lcd_gotoxy(1,2);
     printf(lcd_putc,"STATUS : FULL ");
     delay_ms(2000);
     send_sms3();
     lcd_putc('\f');     
     lcd_gotoxy(4,1);
     printf(lcd_putc,"SMS SENT");
     lcd_gotoxy(1,2);
     printf(lcd_putc,"STATUS : FULL ");
     delay_ms(2000);
     }
     
  //2ND LOW SENSOR

  else if(input(pin_A0)||(!input(pin_A1)))
  {
   output_high(pin_d2);  output_low(pin_d3);  //GREEN LED    
            
     lcd_putc('\f');     
     lcd_gotoxy(0,1);
     printf(lcd_putc,"YOU HAVE RECEIVED");
     lcd_gotoxy(0,2);
     printf(lcd_putc,"COURIER. PLS Check**  ");
     delay_ms(2000);
         
         lcd_putc('\f');     
     lcd_gotoxy(1,1);
     printf(lcd_putc,"SMS SENDING......");
     lcd_gotoxy(1,2);
     printf(lcd_putc,"RECEIVED COURIER ");
     delay_ms(2000);
     send_sms2();
     lcd_putc('\f');     
     lcd_gotoxy(4,1);
     printf(lcd_putc,"SMS SENT");
     lcd_gotoxy(1,2);
     printf(lcd_putc,"RECEIVED COURIER ");
     delay_ms(2000);
     }
     
     
     
     
  //invalid card
  else
  {     output_low(pin_d2);  output_low(pin_d3);  //GREEN LED    
   output_low(pin_d1);         
     lcd_putc('\f');     
     lcd_gotoxy(1,1);
     printf(lcd_putc,"COURIER MAILBOX");
     lcd_gotoxy(1,2);
     printf(lcd_putc,"STATUS : EMPTY ");
     delay_ms(2000);
       
   
  }//else
     
   }//WHILE
      
}//MAIN




