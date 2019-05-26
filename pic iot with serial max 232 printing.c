/*****************************************************************************

****************************************************************************/
#include <16F877A.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#fuses HS,NOWDT,PROTECT,brownout,put
#use delay  (clock=20M)
#use  rs232  (baud = 115200, xmit=PIN_A0, rcv=PIN_A1,stream=ESP)
#use  rs232  (baud = 115200, xmit=PIN_C6, rcv=PIN_C7)
#include <flex_lcd.c>
 /*
 char data='x';
 char chr;
 
void okcheck()
{
 unsigned char rr;
 do{
      rr=fgetc(ESP); 
      //rr = getch(ESP);
   }while(rr != 'K');  // OK
}
*/





void wifiinit()
{
//////////

      
      lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"WAITING FOR OK ");
         delay_ms(1000);



fprintf(ESP,"AT+CIPMUX=0\r\n"); delay_ms(3000); 

fprintf(ESP,"AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n\r\n"); delay_ms(4000);

fprintf(ESP,"AT+CIPSEND=51\r\n\r\n"); delay_ms(3000); 

fprintf(ESP,"GET /update?api_key=KSKI3VUG00JM1U5H&field1=55\r\n"); delay_ms(3000); 

fprintf(ESP,"AT\r\n"); delay_ms(1500); 

fprintf(ESP,"AT\r\n"); delay_ms(1500); 

lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"UPDATE COMPLETED"); delay_ms(1000);  
         
//fprintf(ESP,"AT+CIPCLOSE\r\n\r\n"); delay_ms(3000);

//fprintf(ESP,"AT+RST\r\n\r\n"); delay_ms(3000);

///////////////////

//MAIN PROGRAMMING-------------------------------------------------------------
void main()
{
  
  lcd_init();
      
     
      
      
      
      
       
   //HEALTH CHECK UP..........................................
   output_high(PIN_C4);  //BUZZER ON
   output_high(PIN_C5);  //GREEN LED ON
   output_high(PIN_C3);  //RED LED ON
   delay_ms(1000);
   output_low(PIN_C4);   //BUZZER OFF
   output_low(PIN_C5);
   output_low(PIN_C3);
   delay_ms(1000);
   output_high(PIN_C4);  //BUZZER ON
   output_high(PIN_C5);  //GREEN LED ON
   output_high(PIN_C3);  //RED LED ON
   delay_ms(1000);
   output_low(PIN_C4);   //BUZZER OFF
   output_low(PIN_C5);
   output_low(PIN_C3);
   delay_ms(1000);
   
//DISPLAY INITIAL MESSAGE
          lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"IOT-BSD INTRUDER ");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"DETECT AND ALERT");         
         delay_ms(2000); 
         
          lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"---SYSTEM ---- ");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"--------------- ");         
         delay_ms(2000); 
         
            lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"wifi initializing..."); delay_ms(1000);           
      
      fprintf(ESP,"AT\r\n"); delay_ms(1500); 
    
      fprintf(ESP,"AT+RST\r\n"); delay_ms(3000);
      
      fprintf(ESP,"AT\r\n"); delay_ms(1500); 

fprintf(ESP,"AT+CWJAP=\"project12\",\"project12345\"\r\n"); delay_ms(3000);
         
         
         
        
   wifiinit(); delay_ms(1500);  
   
   
//CONTINEOUS LOOP...........................................
  while(1)
  {
  
  wifiinit(); delay_ms(1500);
  
  

  } // WHILE......................................................................  
  }//MAIN







