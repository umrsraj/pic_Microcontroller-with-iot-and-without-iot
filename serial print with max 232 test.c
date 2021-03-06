/*****************************************************************************
TITLE:
IOT BASED INTRUDER DETECTION AND ALERT SYSTEM OVER ESP8266 WIFI MODULE

ESP8266 WIFI MODULE =A0,A1,
C4=GREEN LED,
C5= RED LED,
C3= BUZZER,
****************************************************************************/
#include <16F877A.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#fuses HS,NOWDT,PROTECT,brownout,put
#use delay  (clock=20M)
#use  rs232  (baud = 115200, xmit=PIN_B0,rcv=PIN_B1,stream=ESP)
#include <flex_lcd.c>
 
 
   
 float temp1,temp2;
 int ir,mems;
 
 float voltageX;
unsigned int voltageY = 10;
unsigned int voltageZ = 10;
 
 
 
 char A[] = "GET /update?api_key=KSKI3VUG00JM1U5H&field1="; 
 char B[] = "&field2=";
 char C[] = "&field3=";
 
 char *postStr[] ="\0";
 //char ciplength[] ="\0";  
 

void wifiinit()
{
//////////

      
      lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"UPDATING");
         delay_ms(1000);

*postStr = strcat (A,voltageX);
*postStr = strcat (postStr,B);
*postStr = strcat (postStr,voltageY);
*postStr = strcat (postStr,C);
*postStr = strcat (postStr,voltageZ);





//===========================================
fprintf(ESP,"AT+CIPMUX=0\r\n"); delay_ms(3000); 

fprintf(ESP,"AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n\r\n"); delay_ms(4000);

fprintf(ESP,"AT+CIPSEND=80\r\n\r\n"); delay_ms(3000); 

fprintf(ESP,"GET /update?api_key=KSKI3VUG00JM1U5H"); delay_ms(30); 
fprintf(ESP,"&field1=%2.0f",voltageX); delay_ms(30);
fprintf(ESP,"&field2=%u",voltageY); delay_ms(30);
fprintf(ESP,"&field3=%u",voltageZ); delay_ms(30);
fprintf(ESP,"\r\n"); delay_ms(3000);

fprintf(ESP,"AT\r\n"); delay_ms(1500);

fprintf(ESP,"AT\r\n"); delay_ms(1500);

fprintf(ESP,"AT\r\n"); delay_ms(1500); 

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
 
 
 
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG ); 
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

fprintf(ESP,"AT+CWJAP=\"project12\",\"rajender12\"\r\n"); delay_ms(3000);
         
         
         
        
    
   
   
//CONTINEOUS LOOP...........................................
  while(1)
  {
  set_adc_channel(0);       //TEMPERATURE ............................                      
      delay_ms(1);
      temp2=read_adc(); 
      delay_ms(1);
      temp1 = (temp2 * 100)/256;
      temp1 = temp1 * 5;
      
      set_adc_channel(1);       //TEMPERATURE ............................                      
      delay_ms(1);
      ir = read_adc(); 
      delay_ms(10);
      
       set_adc_channel(2);       //TEMPERATURE ............................                      
      delay_ms(1);
      mems = read_adc(); 
      delay_ms(10);
      
  
  voltageX = temp1;
  //wifiinit(); delay_ms(1500);
  if (temp1 > 36)
  {
  voltageX = temp1;
   lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Temperature alert");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"--------------- ");         
         delay_ms(2000); 
  }
  
  if (ir > 65)
  {
  voltageY = 100;
   lcd_putc('\f');
  lcd_gotoxy(1,1);
         printf(lcd_putc,"   IR Alert ");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"^^^^^^^^^^^");         
         delay_ms(2000); 
  }
  else 
  {
  voltageY = 0;
  }
  
  if (mems > 65)
  {
  voltageZ = 100;
   lcd_putc('\f');
   lcd_gotoxy(1,1);
         printf(lcd_putc,"   mems Alert ");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"================");         
         delay_ms(2000); 
  
  }
  else 
  {
  voltageZ = 0;
  }
  
  wifiinit(); delay_ms(1500);

  } // WHILE......................................................................  
  }//MAIN







