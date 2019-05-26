/*****************************************************************************
TITLE:
INDUSTRIAL PROTECTION SYSTEM

https://thingspeak.com/channels/562956

PIC16F73

ESP8266 WIFI MODULE =B0,B1,
TEMP = A0
SMOKE = A1
IR = A2 
LCD = B PORT

C4=GREEN LED,
C5= RED LED,
C3= BUZZER,

//===================================================

http://sms.scubedigi.com/api.php?username=Mydreamacd&password=Mydre@m123&to=9652490222&from=MYDREM&message=Rajender

//=============================================================================================
****************************************************************************/
#include <16F73.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#fuses HS,NOWDT,PROTECT,brownout,put
#use delay  (clock=20M)
#use  rs232  (baud = 9600, xmit=PIN_B0,rcv=PIN_B1,stream=ESP)
#include <flex_lcd.c>
 
  

void wifiinit()
{
//////////

      
      lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"UPDATING");
         delay_ms(100);
/*

*postStr = strcat (A,voltageX);
*postStr = strcat (postStr,B);
*postStr = strcat (postStr,voltageY);
*postStr = strcat (postStr,C);
*postStr = strcat (postStr,voltageZ);

*/

//===========================================
fprintf(ESP,"AT+CIPMUX=0\r\n"); delay_ms(1500); 

fprintf(ESP,"AT+CIPSTART=\"TCP\",\"sms.scubedigi.com\",80\r\n\r\n"); delay_ms(2000);

fprintf(ESP,"AT+CIPSEND=104\r\n\r\n"); delay_ms(2000); 

fprintf(ESP,"GET /api.php?username=Mydreamacd&password=Mydre@m123&to="); delay_ms(30); 
fprintf(ESP,"9652490222&from=MYDREM&message=Rajender\r\n"); delay_ms(3000);
//fprintf(ESP,"&field2=%u",voltageY); delay_ms(30);
//fprintf(ESP,"&field3=%u",voltageZ); delay_ms(30);
//fprintf(ESP,"\r\n"); delay_ms(3000);

fprintf(ESP,"AT\r\n"); delay_ms(1000);

fprintf(ESP,"AT\r\n"); delay_ms(1000);

fprintf(ESP,"AT\r\n"); delay_ms(1000); 


fprintf(ESP,"AT+CIPCLOSE\r\n"); delay_ms(3000);

      //fprintf(ESP,"AT+RST\r\n"); delay_ms(3000);

//=========================================


lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"UPDATE COMPLETED"); delay_ms(2000);  
         
}
//MAIN PROGRAMMING-------------------------------------------------------------
void main()
{

 
 //string A = "GET /update?api_key=UJ55O2G2P54P2QIS&field1=";
//String B = "&field2=";
 
 
 
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
         printf(lcd_putc,"   INDUSTRIAL   ");
         lcd_gotoxy(0,2);
         printf(lcd_putc," PROTECTION S/M ");         
         delay_ms(2000); 
         
        
         
            lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"wifi initializing..."); delay_ms(1000);           
      
      fprintf(ESP,"AT\r\n"); delay_ms(1500); 
    
      fprintf(ESP,"AT+RST\r\n"); delay_ms(3000);
      
      fprintf(ESP,"AT\r\n"); delay_ms(1500); 

fprintf(ESP,"AT+CWJAP=\"projec\",\"project123456\"\r\n"); delay_ms(3000);
         
         
         
        
    
   
   
//CONTINEOUS LOOP...........................................
  while(1)
  {
   lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"   INDUSTRIAL   ");
         lcd_gotoxy(0,2);
         printf(lcd_putc," PROTECTION S/M ");         
         delay_ms(2000); 
        
  wifiinit(); delay_ms(1500);

  } // WHILE......................................................................  
  }//MAIN







