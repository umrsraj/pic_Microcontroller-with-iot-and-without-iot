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
#use  rs232  (baud = 115200, xmit=PIN_A0,rcv=PIN_A1,stream=ESP)
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
/*
         lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"wifi initializing..."); delay_ms(1000);           
      
      fprintf(ESP,"AT\n"); delay_ms(1500); 
     // fprintf(ESP,"ATE1\r\n"); delay_ms(500);
      fprintf(ESP,"AT+RST\n"); delay_ms(3000);
      lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"WAITING FOR OK ");delay_ms(500);
     //okcheck();delay_ms(500); 
      fprintf(ESP,"AT+CWMODE=3\n"); delay_ms(2000);
         lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"MODE SET ");delay_ms(500);
         // fprintf(GSM,AT+CWSAP=\"ESP8266MINE\",\"123456\",5,0\r\n");
        fprintf(ESP,"AT+CIPMUX=1\n"); delay_ms(1000);
        fprintf(ESP,"AT+CIPSERVER=1,23\n"); delay_ms(1000);
               
         lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"WAITING FOR IP.. "); delay_ms(1000);
         lcd_gotoxy(3,2);
         printf(lcd_putc,"CONNECTION.... ");
    //  while((fgetc(ESP) != 'C')||(fgetc(ESP) != 'c'));
      while(fgetc(ESP) != 'C');
    
        lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"WIFI CONNECTED ");delay_ms(500);
      */
}


/*
//READ.......
void get_wifi_data()
{
        while(fgetc(ESP) != '+');         //$GPRMC,120029.000,V,0000.0000,N,00000.0000,E,000.0,000.0,280606,,,N*74
      if(fgetc(ESP) == '+')
        if(fgetc(ESP) == 'P')           //$GPRMC,022042.000,V,1720.1007,N,07832.9310,E,004.3,227.6,190815,,,N*75
          if(fgetc(ESP) == 'D')
           while(fgetc(ESP) != ':');
                   data = fgetc(ESP);
                 
  
  }
  
  
  void beep()
  {
  output_high(pin_C3);
  delay_ms(1000);
  output_low(pin_C3);
  delay_ms(700);
  
  }
  
  
  void buzzer()
  {
  output_high(pin_C3);
  delay_ms(2000);
  output_low(pin_C3);
  delay_ms(100);
  
  }
  */
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
   
   /*
  fprintf(ESP,"AT+CIPSEND=0,57\n"); delay_ms(1000);
  fprintf(ESP,"\nWELCOME!!! IOT-BSD INTRUDER DETECTION AND ALERT SYSTEM \r\n"); delay_ms(1000);
         lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc," WELCOME!!!!");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"--------------- ");         
         delay_ms(2000); 
         */
//CONTINEOUS LOOP...........................................
  while(1)
  {
  
  wifiinit(); delay_ms(1500);
  
  
/*
//---------------------------------
if(input(pin_b0))   //if PIR SENSOR ACTIVATED----- 
{
      output_high(pin_c5);
      output_low(pin_c4);
      beep();      
      printf(lcd_putc,"\f");
      lcd_gotoxy(0,1);
      printf(lcd_putc,"INTRUDER***ALERT**");
      lcd_gotoxy(0,2);
      printf(lcd_putc,"--PLS CHECK...--");
      //printf(lcd_putc," TEMP=%2.0g%cC",temp2,0xDF);
      fprintf(ESP,"AT+CIPSEND=0,29\n"); delay_ms(1000);
      fprintf(ESP,"\nINTRUDER***ALERT**PLS CHECK**\r\n");delay_ms(1000);
      output_low(pin_c5); //GREEN OFF
      output_high(pin_c4); //RED LED ON
      delay_ms(700); 
}



//ELSE PIR = OFF
else
{

          lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"STSTEM IS OK");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"------------");         
      fprintf(ESP,"AT+CIPSEND=0,17\n"); delay_ms(1000);
      fprintf(ESP,"\n--SYSTEM IS OK--\r\n");delay_ms(1000);
         //output_low(pin_d7);output_low(pin_d6);   //REL On
         output_high(pin_C4);  //GREEN LED ON
         output_low(pin_C5);  //RED LED OFF
         delay_ms(2000);

}
*/
  } // WHILE......................................................................  
  }//MAIN







