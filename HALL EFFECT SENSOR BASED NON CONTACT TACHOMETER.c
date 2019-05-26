/*
TITLE: HALL EFFECT SENSOR BASED NON CONTACT DIGITAL TACHOMETER
PIC16F877A,
HALL EFFECT SENSOR = B0 ,
D2= GREEN LED FOR COUNT,
CO TO GND = L293D MOTOR DRIVER,

*/



#include <16F877A.h>           //Microcontroller Used
#fuses    HS,NOWDT,PROTECT,brownout,put
#use      delay(clock=20M)          // operating Clock freequency
#include "flex_lcd.c"
#include "dc motor.c"    //DC MOTOR HEADER FILE

void main()
{
   unsigned int16 value=0;
   
   lcd_init();

       printf(lcd_putc,"\f");
       lcd_gotoxy(0,1);
       printf(lcd_putc,"HALL EFFEC SENSOR  "); 
       lcd_gotoxy(0,2);
       printf(lcd_putc,"BSD NON-CONTACT ");     
       delay_ms(2500);
     
          printf(lcd_putc,"\f");
       lcd_gotoxy(0,1);
      printf(lcd_putc,"DIGITAL TACHOMETER "); 
       lcd_gotoxy(0,2);
      printf(lcd_putc,"********************");     
     delay_ms(2500);
     
     
     output_high(pin_d2);   output_high(pin_d3);
     delay_ms(1000);
     output_low(pin_d2);  output_low(pin_d3);
          delay_ms(1000);
     output_high(pin_d2);   output_high(pin_d3);
     delay_ms(1000);
     output_low(pin_d2);  output_low(pin_d3);
          delay_ms(1000);
          
     printf(lcd_putc,"\f");
 
 forword1();
forword2();

   while(1)
   {  
         
           
          if(!input(pin_B0))
           {
           output_high(pin_D2);    
           value+=1;
      //  printf(lcd_putc,"\f");
      lcd_gotoxy(2,1);
      printf(lcd_putc,"LIVE SPEED"); 
      lcd_gotoxy(3,2);
      printf(lcd_putc,"RPM:%LU",value);
      output_low(pin_c4);
      delay_ms(100);
           }
       
     else{
       if(value==1)
     {
      value=0; 
      printf(lcd_putc,"\f");
      lcd_gotoxy(2,1);
      printf(lcd_putc,"LIVE SPEED"); 
       lcd_gotoxy(5,2);
     lcd_gotoxy(3,2);
      printf(lcd_putc,"RPM: %LU",value);
      // output_low(pin_c4);
      delay_ms(100);
     }
     if(value>1)
     {
      value-=1;
      //  printf(lcd_putc,"\f");
      // lcd_gotoxy(2,1);
     // printf(lcd_putc,"LIVE SPEED"); 
       lcd_gotoxy(3,2);
      printf(lcd_putc,"RPM: %LU",value);
      // output_low(pin_c4);
      delay_ms(30);
     }
     
     } //else    
   
      }
                              
      }

    







