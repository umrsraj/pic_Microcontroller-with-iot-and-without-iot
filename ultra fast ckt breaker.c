/******************************************************************************************
TITLE: ULTRA FAST ACTING ELECTRONIC CIRCUIT BREAKER
PIC16F877a,

CT = A0
RELAY WITH MOSFET = C1
out IR= E2
LCD = B PORT
G LED = d2
R LED = d3

*******************************************************************************************/
#include <16f877A.h>
#fuses HS,PUT,NOWDT,NOPROTECT
#use delay(clock=20000000)
//#define ADC=8
#include "flex_lcd.c"








void main() 
{

unsigned int ct = 0;
//unsigned int inir = 0;
//unsigned int outir = 0;

   lcd_init();
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );
   
    // ext_int_edge(H_TO_L);       // Interrupt on falling edge of RB0/INT pin
//  ext_int_edge(L_TO_H);       // Interrupt on falling edge of RB0/INT pin
  //clear_interrupt(INT_EXT);   // Clear RB0/INT external interrupt flag bit
  //enable_interrupts(INT_EXT); // Enable RB0/INT external interrupt
  //enable_interrupts(GLOBAL);  // Enable all unmasked interrupt
   
   
output_high(pin_d2);
output_high(pin_d3);

   delay_ms(500);
   
output_low(pin_d2);
output_low(pin_d3);

 delay_ms(500);
   
output_high(pin_d2);
output_high(pin_d3);

   delay_ms(500);
   
output_low(pin_d2);
output_low(pin_d3);

 delay_ms(500);
   
   
   
     //      output_low(pin_D0); 
         output_low(pin_C1);
     
  //display initial messsage ....................................
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"ULTRA FAST ACTING");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"   ELECTRONIC   ");
              delay_ms(2000);
           
           printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"  CKT BREAKER  ");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"*******************");
              delay_ms(1700);
           
           
    while(TRUE)
    {
        
      set_adc_channel(0);
      delay_ms(50);// delay built-in function call
      ct = Read_ADC();                   // A/D read functions- built-in         
      
 if(ct > 30)
        {
        output_low(pin_c1);
        
       output_low(pin_d2);
output_high(pin_d3);



              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"OVER CURRENT");
              lcd_gotoxy(1,2);
              printf(lcd_putc," FAST SWITCH ON ");
              delay_ms(10);
              while(ct>30);
            

        }
        
        
        
   else 
   {
   output_high(pin_d2);
output_low(pin_d3);

 output_high(pin_c1);
 
    printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"SYSTEM IS NORMAL");
              lcd_gotoxy(1,2);
              printf(lcd_putc," CURRENT = %u mA",ct);
              delay_ms(10);
              
   
   }
    
           
           
    } //while loop
}  //main loop

