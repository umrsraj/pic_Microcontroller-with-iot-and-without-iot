/*
AUTOMATIC WATER LEVEL CONTROLLER USING GSM

PIC16F877A
LCD= B2 TO B7 PORT
A0 = IR SENSOR 1  AT BOTTOM,
A1 = IR SENSOR 2  AT MEDIUM
A2= IR SENSOR 2 AT TOP,

L293D DC MOTOR DRIVER= C0 TO GND
GSM=B0,B1,
D1 = BUZZER,
D2,D3,C4= G ,Y AND R LED'S

IR SENSOR 4= E2 PERSON DETECTION

*/

#include <16F877A.h>           //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use     delay(clock=20M)          // operating Clock freequency
#use     rs232  (baud = 9600, rcv=PIN_B1, xmit=PIN_B0,stream=GSM)
#include "flex_lcd.c"
#include "dc_motor.c"
//WELCOME MESSAGE SENDING
void send_sms1()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9492297120\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM," WELCOME!! AUTOMATIC WATER LEVEL MONITORING USING GSM.\r\n");
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
fprintf(GSM,"AT+CMGS=\"8179457667\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM," WELCOME!! AUTOMATIC WATER LEVEL MONITORING USING GSM.\r\n");
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
fprintf(GSM,"AT+CMGS=\"9652963011\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM," WELCOME!! AUTOMATIC WATER LEVEL MONITORING USING GSM.\r\n");
delay_ms(1000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 
}


//3RD FULL
void send_sms2()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9492297120\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"WATER LEVEL = FULL, MOTOR = OFF.  \r\n");
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
fprintf(GSM,"AT+CMGS=\"8179457667\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"WATER LEVEL = FULL, MOTOR = OFF.  \r\n");delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(5000);


//3rd message
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9652963011\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"WATER LEVEL = FULL, MOTOR = OFF.  \r\n");delay_ms(1000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(5000);
}

// HALF
void send_sms3()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9492297120\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 


fprintf(GSM,"WATER LEVEL = LOW, MOTOR = ON.  \r\n");delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(5000); 

//2nd message
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"8179457667\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"WATER LEVEL = LOW, MOTOR = ON.  \r\n");
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
fprintf(GSM,"AT+CMGS=\"9652963011\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM,"WATER LEVEL = LOW, MOTOR = ON.  \r\n");delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(5000);
}




void show_projectname()
{
      lcd_putc('\f');
      lcd_gotoxy(0,1);
      printf(lcd_putc,"DUSTBIN MONITORING  ");
      lcd_gotoxy(2,2);
      printf(lcd_putc,"& ALERT SYSTEM  ");
      delay_ms(2000);
     
         lcd_putc('\f');
      lcd_gotoxy(0,1);
      printf(lcd_putc," BY--> RAMYASAHATHI, ");
      lcd_gotoxy(0,2);
      printf(lcd_putc,"SOUMYA & SHIVANI ");
      delay_ms(2000);
}



void main() 
{ 
    
   lcd_init(); 
  show_projectname();


 //HEALTH CHECK UP
output_high(pin_d2);  //GREEN LED
output_high(pin_d3);  //RED LED
output_high(pin_C4);  //GREEN LED
delay_ms(1000);
output_low(pin_d2); //GREEN LED OFF
output_low(pin_d3); //RED LED OFF
output_low(pin_C4); //RED LED OFF
delay_ms(1000);
output_high(pin_d2);  //GREEN LED
output_high(pin_d3);  //RED LED
output_high(pin_C4);  //GREEN LED
delay_ms(1000);
output_low(pin_d2); //GREEN LED OFF
output_low(pin_d3); //RED LED OFF
output_low(pin_C4); //RED LED OFF
delay_ms(1000);

send_sms1();delay_ms(3000);
output_high(pin_d2);  //GREEN LED
output_high(pin_d3);  //RED LED
output_high(pin_C5);  //GREEN LED
delay_ms(1000);
output_low(pin_d2); //GREEN LED OFF
output_low(pin_d3); //RED LED OFF
output_low(pin_C4); //RED LED OFF

  
   
  while (1)
  {
      //FULL
  if((input(pin_A0))&&(input(pin_A1))&&(input(pin_A2)))
  {
   output_high(pin_d2);  output_high(pin_d3);    output_high(pin_c5);  
           output_low(pin_d7); 
     
     send_sms2();
         delay_ms(1000);
     }
     
 
  //DUSTBIN = MID LEVEL
 else if((input(pin_A0))&&(input(pin_A1))&&(!input(pin_A2)))
  {
  output_high(pin_d2);  output_high(pin_d3);    output_low(pin_c5);
    output_high(pin_d7);      
        
   delay_ms(1000);
    
     }
    
    
 //LOW LEVEL -1
   //DUSTBIN = MID LEVEL
 else if((input(pin_A0))&&(!input(pin_A1))&&(!input(pin_A2)))
  {
  output_high(pin_d7);
  output_high(pin_d2);  output_low(pin_d3);    output_low(pin_c4);     
           

     delay_ms(1000);
         
       
     }
    
   
     
     
  //invalid card
  else
  {      output_high(pin_d7); 
  output_low(pin_d2);  output_low(pin_d3); output_low(pin_c4); //GREEN LED
           output_high(pin_d7);
           send_sms3();
    
     delay_ms(500);
       
   
  }//else
     
   }//WHILE
      
}//MAIN




