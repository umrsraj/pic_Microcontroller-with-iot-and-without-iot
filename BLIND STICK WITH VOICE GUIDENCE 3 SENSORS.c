/*****************************************************************************
TITLE:
SMART BLIND STICK WITH ULTRASONIC IR AND WATER WIH APR

 D2=GREEN LED,
 D3= RED LED,
 
 A0 = ULTRASONIC SENSOR,
 A2= IR SENSOR,
 A3= WATER SENSOR
 
 C0,C1,C2,C3,D0,D1= APR VOICE MODULE,
 D7= BUZZER,
****************************************************************************/
#include <16F877A.h>
#include <stdlib.h>
#fuses  HS,NOWDT,PROTECT,brownout,put
#use  delay  (clock=20M)
#include <flex_lcd.c>

//MAIN PROGRAMMING-------------------------------------------------------------
void main()
{
  
   lcd_init(); 
  
//DISPLAY INITIAL MESSAGE
          lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"VOICE GUIDENCE1 BSD");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"SMART BLIND STICK ");         
         delay_ms(2000); 
                  
           //APR 9600 VOICE MODULE
   output_high(PIN_C0);  
   output_high(PIN_C1);  
   output_high(PIN_C2);  
   output_high(PIN_C3); 
   output_high(PIN_D0);  
   output_high(PIN_D1);  
  
   
          output_low(PIN_C0);
         delay_ms(200);
         output_high(PIN_C0);
         
         //HEALTH CHECK UP..........................................
 //  output_high(PIN_c4);  //BUSSER ON
   output_high(PIN_D2);  //GREEN LED ON
   output_high(PIN_D3);  //RED LED ON
   delay_ms(500);
  // output_low(PIN_c4);
   output_low(PIN_D2);
   output_low(PIN_D3);
   delay_ms(500);
 //  output_high(PIN_c4);  //BUSSER ON
   output_high(PIN_D2);  //GREEN LED ON
   output_high(PIN_D3);  //RED LED ON
   delay_ms(500);
  // output_low(PIN_c4);
   output_low(PIN_D2);
   output_low(PIN_D3);
   delay_ms(500);//
      
lcd_putc('\f');
        
//CONTINEOUS LOOP...........................................
  while(1)
  {
  
       lcd_putc('\f');
        lcd_gotoxy(0,1);
         printf(lcd_putc,"SMRT BLIND STICK ");
         lcd_gotoxy(1,2);
         printf(lcd_putc,">----------->>>");
         delay_ms(700);  

       
      

//IF MANHOLE OR STEPS DETECTED
if(!input(pin_A0))  // IF MANHOL/ STEPS DETECT
  {
     output_high(pin_d3);   //  RED LED ON
     output_low(pin_d2);   // GREEN LED ON
     
     //APR VOICE ALERT
         output_low(PIN_C2);
         delay_ms(100);
         output_high(PIN_C2);
         
             
     printf(lcd_putc,"\f");
     lcd_gotoxy(1,1);
     printf(lcd_putc,"MANHOLE/STEPS");
     lcd_gotoxy(0,2);
     printf(lcd_putc,"DETECTED. PLS STOP**");
      delay_ms(1000);
  }

   
//WAER LEVEL DETECT
if(input(pin_A3))
  {
     output_high(pin_d3);   //  RED LED ON
     output_low(pin_d2);   // GREEN LED ON
     
     //APR VOICE ALERT
         output_low(PIN_C3);
         delay_ms(100);
         output_high(PIN_C3);
         
             
     printf(lcd_putc,"\f");
     lcd_gotoxy(1,1);
     printf(lcd_putc," WATER DETECTED");
     lcd_gotoxy(1,2);
     printf(lcd_putc," **PLS STOP**");
       
      delay_ms(1000);
  }


//OBSTACLE AERT
//IF ACCIDENT OCCUR /////////////////////////////////////////////////////MEMS VAUES AT FOUR DIRECTIONS/////////////////////////////

//IF OBSTACLE DETECT.......................................
 if(input(pin_b0))
  {
     output_high(pin_d3);   //  RED LED ON
     output_low(pin_d2);   // GREEN LED ON
     //output_high(pin_B0);   //BUZZER ON        
     
  //APR VOICE ALERT
      output_low(PIN_C1);
      delay_ms(100);
     output_high(PIN_c1);
     //output_low(pin_B0);   //BUZZER Off       
     
     printf(lcd_putc,"\f");
     lcd_gotoxy(1,1);
     printf(lcd_putc,"OBSTACLE ALERT");
      lcd_gotoxy(1,2);
      printf(LCD_PUTC, "PLS CHECK******"); // print distance on lcd
      delay_ms(1000);
  }
        output_high(pin_D2);  //GREEN LED ON
        output_low(pin_D3);  //RED LED OFF
        delay_ms(100);
           //APR 9600 VOICE MODULE
   output_high(PIN_C0);  
   output_high(PIN_C1);  
   output_high(PIN_C2);  
   output_high(PIN_C3); 
   output_high(PIN_D0);  
   output_high(PIN_D1); 
     

  }// WHILE......................................................................  
  
}//MAIN








