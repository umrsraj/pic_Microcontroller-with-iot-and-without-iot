
/***************************************************************************************************************************

Project Title:  SMART AUDITORIUM
Bidirectional Visitor counter with Maximum capacity alarm



****************************************************************************************************************************/

#include <16f73.h>
#fuses HS,PUT,NOWDT,PROTECT
#use delay(clock=20M)
#include "flex_lcd.c"


void main()
{
   int i=0,j=0,tot,flag=0;                     //i=in count;  j=out count;   tot=total count 
   
   output_high(pin_C4);
   output_high(pin_C5);
   output_high(pin_C3);
   delay_ms(500);
   output_low(pin_C4);
   output_low(pin_C5);
   output_low(pin_C3);
   delay_ms(500);
   output_high(pin_C4);
   output_high(pin_C5);
   output_high(pin_C3);
   delay_ms(500);
   output_low(pin_C4);
   output_low(pin_C5);
   output_low(pin_C3);
   delay_ms(500); 
   lcd_init();
   printf(lcd_putc,"\f");
   lcd_gotoxy(0,1);
   printf(lcd_putc,"ENERGY SAVING ");
  // delay_ms(2000);
   lcd_gotoxy(0,2);
   printf(lcd_putc,"IN AUDITORIUMS ");
   delay_ms(2000);
  /* 
      printf(lcd_putc,"\f");
   lcd_gotoxy(0,1);
   printf(lcd_putc,"IN AUDITORIUMS ");
  // delay_ms(2000);
   lcd_gotoxy(0,2);
   printf(lcd_putc,"BSD ON STRENGTH  ");
   delay_ms(2000);
 */
   printf(lcd_putc,"\f");
   lcd_gotoxy(0,1);
   printf(lcd_putc,"OUR GUIDE-V.INDRA  ");
  // delay_ms(2000);
   lcd_gotoxy(3,2);
   printf(lcd_putc," PRIYADARSINI  ");
   delay_ms(3000);
 
      printf(lcd_putc,"\f");
   lcd_gotoxy(1,1);
   printf(lcd_putc,"I=%u,O=%u,T=%u ",i,j,tot);
   lcd_gotoxy(1,2);
   printf(lcd_putc,"L1:1  , L2:0"); 
   delay_ms(1500);
   
   
   while(1)
   {
   
   
      if(flag==1)
      {
         if(input(pin_B0))                       //OUT entrance
         {
            j=j+1;
            output_high(pin_C4);
            delay_ms(500);
            output_low(pin_C4);
            delay_ms(500);
       }
     }

      if(input(pin_A0))                    //IN entrance
      {
        i = i + 1;
        output_high(pin_C5);
        delay_ms(500);
        output_low(pin_C5);
        delay_ms(500);
        flag=1;
      }
         
      if(j > i)
      j = j - 1;

      tot=i-j;

     if(tot == 255)                           // IF out IR is cut first, the system will not respond
      tot = 0;
         
      lcd_gotoxy(1,1);
      printf(lcd_putc,"I=%u,O=%u,T=%u ",i,j,tot);
      delay_ms(500);
        
      if(tot == 0)                         // count in the hall is ZERO
      {
        output_low(pin_c6);
        output_low(pin_c7);
        output_low(pin_c4);output_low(pin_c5);
        delay_ms(500);
        lcd_gotoxy(1,2);
        printf(lcd_putc,"L1:0 , L2:0");   
      }
      
      if(tot <= 5 && tot > 0)           // count in the hall in between 1-5
      {
        output_high(pin_c6);
      //  output_high(pin_c4);  //g led
        output_low(pin_c7);
        // output_low(pin_c5);
        delay_ms(500);
        lcd_gotoxy(1,2);
        printf(lcd_putc,"L1:1  , L2:0");  
      }

      else if(tot > 5)                        // count in the hall above 5
      {
        output_high(pin_c7);
      //  output_high(pin_c4); output_high(pin_c5); 
        lcd_gotoxy(1,2);
        printf(lcd_putc,"L1:1  , L2:1 ");  ;  
      }

      if(tot > 15)                           // count in the hall above 15
      {
     //  output_high(pin_c5);  //
    //   output_low(pin_c4);  //g off
      output_high(pin_c3);               // Buzzer ON
   //     output_low(pin_c5);  //g led
      delay_ms(1000);
      output_low(pin_c3);
           
     }

      else if(tot<=15)
      {
      output_low(pin_c3);               // Buzzer ON
     // output_low(pin_c5);                // Buzzer OFF
       }



   
   }
}


