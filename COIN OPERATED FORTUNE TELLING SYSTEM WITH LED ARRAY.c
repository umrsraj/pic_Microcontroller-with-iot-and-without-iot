/******************************************************************************************
TITLE: COIN OPERATED FORTUNE TELLING SYSTEM WITH LED ARRAY
PIC16F877A,
LCD= B PORT
IR SENSOR= B0(INTERRUPT)'
D2 TO D7 =10 LED ARRAY,
D1= BUZZER,
*******************************************************************************************/
#include <16F877A.h>
#FUSES HS,PUT
#use delay(clock=20M)
#include <flex_lcd.c>

int flag=0;


void beep()
{
output_high(pin_d1);   delay_ms(300);output_low(pin_d1);
 delay_ms(300);
 output_high(pin_d1);   delay_ms(300);output_low(pin_d1);
 delay_ms(300);
 output_high(pin_d1);   delay_ms(300);output_low(pin_d1);
 delay_ms(300);
 output_high(pin_d1);   delay_ms(300);output_low(pin_d1);
 delay_ms(300);
 output_high(pin_d1);   delay_ms(300);output_low(pin_d1);
 delay_ms(300);
  output_high(pin_d1);   delay_ms(1500);output_low(pin_d1);
}

void leddance()
{
output_low(pin_d2);output_low(pin_d3);output_low(pin_c4);output_low(pin_c5);output_low(pin_c6);
output_low(pin_c7);output_low(pin_d4);output_low(pin_d5);output_low(pin_d6);output_low(pin_d7);
 delay_ms(200);
output_high(pin_d2);output_high(pin_d3);output_high(pin_C4);output_high(pin_C5);output_high(pin_C6);
output_high(pin_C7);output_high(pin_D4);output_high(pin_d5);output_high(pin_d6);output_high(pin_d7);
   delay_ms(200);
   
   output_low(pin_d2);output_low(pin_d3);output_low(pin_c4);output_low(pin_c5);output_low(pin_c6);
output_low(pin_c7);output_low(pin_d4);output_low(pin_d5);output_low(pin_d6);output_low(pin_d7);
 delay_ms(200);
output_high(pin_d2);output_high(pin_d3);output_high(pin_C4);output_high(pin_C5);output_high(pin_C6);
output_high(pin_C7);output_high(pin_D4);output_high(pin_d5);output_high(pin_d6);output_high(pin_d7);
  delay_ms(700);
  
  output_low(pin_d2);output_low(pin_d3);output_low(pin_c4);output_low(pin_c5);output_low(pin_c6);
output_low(pin_c7);output_low(pin_d4);output_low(pin_d5);output_low(pin_d6);output_low(pin_d7);
 delay_ms(200);
output_high(pin_d2);output_high(pin_d3);output_high(pin_C4);output_high(pin_C5);output_high(pin_C6);
output_high(pin_C7);output_high(pin_D4);output_high(pin_d5);output_high(pin_d6);output_high(pin_d7);
  delay_ms(700);
  
  output_low(pin_d2);output_low(pin_d3);output_low(pin_c4);output_low(pin_c5);output_low(pin_c6);
output_low(pin_c7);output_low(pin_d4);output_low(pin_d5);output_low(pin_d6);output_low(pin_d7);
 delay_ms(200);
output_high(pin_d2);output_high(pin_d3);output_high(pin_C4);output_high(pin_C5);output_high(pin_C6);
output_high(pin_C7);output_high(pin_D4);output_high(pin_d5);output_high(pin_d6);output_high(pin_d7);
  delay_ms(700);
  
//2nd design
  output_low(pin_d2); delay_ms(100);output_low(pin_d3); delay_ms(100);output_low(pin_c4); delay_ms(100);output_low(pin_c5);delay_ms(100);
  output_low(pin_d7);delay_ms(100);output_low(pin_d6);delay_ms(100);output_low(pin_d5);delay_ms(100);delay_ms(100);output_low(pin_d4);delay_ms(100);output_low(pin_c7);
  delay_ms(100);output_low(pin_c6);delay_ms(100);
  output_high(pin_d2);output_high(pin_d3);output_high(pin_C4);output_high(pin_C5);output_high(pin_C6);
  output_high(pin_C7);output_high(pin_D4);output_high(pin_d5);output_high(pin_d6);output_high(pin_d7);
  delay_ms(500); 
  
  output_low(pin_d2); delay_ms(100);output_low(pin_d3); delay_ms(100);output_low(pin_c4); delay_ms(100);output_low(pin_c5);delay_ms(100);
  output_low(pin_d7);delay_ms(100);output_low(pin_d6);delay_ms(100);output_low(pin_d5);delay_ms(100);delay_ms(100);output_low(pin_d4);delay_ms(100);output_low(pin_c7);
  delay_ms(100);output_low(pin_c6);delay_ms(100);
  output_high(pin_d2);output_high(pin_d3);output_high(pin_C4);output_high(pin_C5);output_high(pin_C6);
  output_high(pin_C7);output_high(pin_D4);output_high(pin_d5);output_high(pin_d6);output_high(pin_d7);
  delay_ms(500);  
  
    output_low(pin_d2); delay_ms(100);output_low(pin_d3); delay_ms(100);output_low(pin_c4); delay_ms(100);output_low(pin_c5);delay_ms(100);
  output_low(pin_d7);delay_ms(100);output_low(pin_d6);delay_ms(100);output_low(pin_d5);delay_ms(100);delay_ms(100);output_low(pin_d4);delay_ms(100);output_low(pin_c7);
  delay_ms(100);output_low(pin_c6);delay_ms(100);
  output_high(pin_d2);output_high(pin_d3);output_high(pin_C4);output_high(pin_C5);output_high(pin_C6);
  output_high(pin_C7);output_high(pin_D4);output_high(pin_d5);output_high(pin_d6);output_high(pin_d7);
  delay_ms(500);  
    
 //3rd   
   output_low(pin_d2);output_low(pin_d3);output_low(pin_c4);output_low(pin_c5);output_low(pin_c6);
output_low(pin_c7);output_low(pin_d4);output_low(pin_d5);output_low(pin_d6);output_low(pin_d7);
 delay_ms(100);
output_high(pin_d2);output_high(pin_d3);output_high(pin_C4);output_high(pin_C5);output_high(pin_C6);
output_high(pin_C7);output_high(pin_D4);output_high(pin_d5);output_high(pin_d6);output_high(pin_d7);
   delay_ms(500);
   
     output_low(pin_d2);output_low(pin_d3);output_low(pin_c4);output_low(pin_c5);output_low(pin_c6);
output_low(pin_c7);output_low(pin_d4);output_low(pin_d5);output_low(pin_d6);output_low(pin_d7);
 delay_ms(100);
output_high(pin_d2);output_high(pin_d3);output_high(pin_C4);output_high(pin_C5);output_high(pin_C6);
output_high(pin_C7);output_high(pin_D4);output_high(pin_d5);output_high(pin_d6);output_high(pin_d7);
   delay_ms(100);
}

#INT_EXT
void ext_isr(void)
{
  flag=1;
  
 }



void main() 
{
   lcd_init();
   
       // ext_int_edge(H_TO_L);       // Interrupt on falling edge of RB0/INT pin
  ext_int_edge(L_TO_H);       // Interrupt on falling edge of RB0/INT pin
  clear_interrupt(INT_EXT);   // Clear RB0/INT external interrupt flag bit
  enable_interrupts(INT_EXT); // Enable RB0/INT external interrupt
  enable_interrupts(GLOBAL);  // Enable all unmasked interrupt
   
/*   

output_low(pin_d2);output_low(pin_d3);output_low(pin_c4);output_low(pin_c5);output_low(pin_c6);
output_low(pin_c7);output_low(pin_d4);output_low(pin_d5);output_low(pin_d6);output_low(pin_d7);
   delay_ms(500);
   output_high(pin_d2);output_high(pin_d3);output_high(pin_C4);output_high(pin_C5);output_high(pin_C6);
output_high(pin_C7);output_high(pin_D4);output_high(pin_d5);output_high(pin_d6);output_high(pin_d7);
   delay_ms(500);
*/
 
  
 //beep();  
           
     
  //display initial messsage ....................................
              printf(lcd_putc,"\f");
              lcd_gotoxy(3,1);
              printf(lcd_putc,"COIN OPERATED   ");
              lcd_gotoxy(2,2);
              printf(lcd_putc,"FOTUNE TELLING ");
              delay_ms(2000);
              
             printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"SYS WITH DANCING");
              lcd_gotoxy(3,2);
              printf(lcd_putc," LED EFFECT");
              delay_ms(2000);
              
            /*    
             printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"BY>-->>GOMATHI,");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"VINITHA & VIVEK");
              delay_ms(6000);
              */
       
           
    while(TRUE)
    {
        
       
   //IF COIN INSERTED PROPERLY......................... 
       if(flag==1)  
       {
        beep();
        leddance();          
             printf(lcd_putc,"\f");
              lcd_gotoxy(2,1);
              printf(lcd_putc,"COIN INSERTED  ");
              lcd_gotoxy(0,2);
              printf(lcd_putc,">>--PROPERLY--->>  ");
            delay_ms(2000);
       
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"STARTTED.............  ");
              lcd_gotoxy(3,2);
              printf(lcd_putc,"--------------------- ");
              delay_ms(2000);
          flag=0;
          
           }
       
      else
          {
            
              printf(lcd_putc,"\f");
              lcd_gotoxy(2,1);
              printf(lcd_putc,"INSERT COIN ");
              lcd_gotoxy(3,2);
              printf(lcd_putc,"Please........");
                delay_ms(300);
           }
          
    } //while loop
}  //main loop



