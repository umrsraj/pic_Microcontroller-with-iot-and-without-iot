/********************************************************************************

TITLE:ANTI PREVENTION USING EYE BLINK SENSOR
PIC16F877A,
EYE BLINK = C0  COUNTER,  TIMER1 =C0 (IS THE COUNTER)
D2,D3= LED'S,
LCD= B2 TO B7,
D7= RELAY SWITCH FOR IGNTION CONTROL
D1= BUZZER
*******************************************************************************/
#include <16F877A.h>           //Microcontroller Used
#fuses  HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include "flex_lcd.c"

void beep()
{
output_high(pin_d1);
delay_ms(1000);
output_low(pin_d1);
}


//MAIN PROGRAM.............................................................
void main()
{
  unsigned int16 value;
     lcd_init();
   printf(lcd_putc,"\f");
   lcd_gotoxy(0,1);
   printf(lcd_putc,"ANTI PREVENTION ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"USING EYE BLINK    ");
   delay_ms(2000);
   
     printf(lcd_putc,"\f");
   lcd_gotoxy(4,1);
   printf(lcd_putc,"SENSOR ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"-----------------  ");
   delay_ms(2000);
   
   //health check
    output_high(pin_D2);       // LED ON
    output_high(pin_D3);       //LED ON
    delay_ms(500);beep();
    output_low(pin_D2);
    output_low(pin_D3);
    delay_ms(500);
    output_high(pin_D2);       // LED ON
    output_high(pin_D3);       //LED ON
    delay_ms(500);
    output_low(pin_D2);
    output_low(pin_D3);
    delay_ms(500);  
   // printf(lcd_putc,"\f");
    
 
 
   while(1)
   {  
   
      set_timer1(0);   
      setup_timer_1(t1_external | T1_DIV_BY_1);//c0
        delay_ms(4000);         
         setup_timer_1(T1_DISABLED);
      value=get_timer1();
      
   //    printf(lcd_putc,"\f");
     // lcd_gotoxy(1,1);
     // printf(lcd_putc,"count=%LU",value); 
     //delay_ms(500);
     
  
     if((value>2))
      {
       output_high(pin_D7);
       output_high(pin_D2);
       output_low(pin_D3);
       output_low(pin_D1);     
      printf(lcd_putc,"\f");
      lcd_gotoxy(3,1);
      printf(lcd_putc,"SYSTEM IS OK");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"VEHICLE MOVING.....");
      delay_ms(1000);
      }       
      else
 {
    
      if(value<=1)
      {
       printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"DROWSY DETECTED "); 
      lcd_gotoxy(0,2);
      printf(lcd_putc,"**VEHICLE STOP**"); 
      beep();  
      output_low(pin_D2);
      output_high(pin_D3);  
      output_low(pin_D7);    
       delay_ms(2000); 
      }
        
      
 } //else
    
      }
                              
      }










