/******************************************************************************************
TITLE: autoamtic railway gate control system
PIC16F877a,

in IR = A0
out IR= E2
LCD = B PORT
motor = d0,d1
G LED = d2
R LED = d3

*******************************************************************************************/
#include <16f877A.h>
#fuses HS,PUT,NOWDT,NOPROTECT
#use delay(clock=20000000)
//#define ADC=8
#include "flex_lcd.c"
//#define PIN_D1 pin_d1


void beep ()
{
output_high(PIN_D1);
delay_ms(1000);
output_low(PIN_D1);
delay_ms(10);

}

void main() 
{
unsigned int vol = 0;
unsigned int freq = 0;

   lcd_init();
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );
   
    // ext_int_edge(H_TO_L);       // Interrupt on falling edge of RB0/INT pin
//  ext_int_edge(L_TO_H);       // Interrupt on falling edge of RB0/INT pin
  //clear_interrupt(INT_EXT);   // Clear RB0/INT external interrupt flag bit
  //enable_interrupts(INT_EXT); // Enable RB0/INT external interrupt
  //enable_interrupts(GLOBAL);  // Enable all unmasked interrupt
   
   output_high(PIN_D1);
output_high(pin_d2);
output_high(pin_d3);

   delay_ms(500);
   
   output_low(PIN_D1);
output_low(pin_d2);
output_low(pin_d3);

 delay_ms(500);
   
 output_high(PIN_D1);
output_high(pin_d2);
output_high(pin_d3);


   delay_ms(500);
   
 output_low(PIN_D1);
output_low(pin_d2);
output_low(pin_d3);;

 delay_ms(500);
   
   
   
          
     
  //display initial messsage ....................................
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"  DETECTING OF  ");
              lcd_gotoxy(0,2);
              printf(lcd_putc," POWER GRID SYNC");
              delay_ms(1800);
              
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"   FAILURE S/M   ");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"******************");
              delay_ms(1500);
              
           
    while(TRUE)
    {
        
      set_adc_channel(0);
      delay_ms(50);// delay built-in function call
      vol = Read_ADC();                   // A/D read functions- built-in         
             
        set_adc_channel(1);
      delay_ms(50);// delay built-in function call
      freq = Read_ADC();                   // A/D read functions- built-in         
      
  
      if(freq>60)
      {
      freq = 60;
      }
      
      
      
        if((vol>240)||(vol<220))
        {
       output_low(pin_d2);
output_high(pin_d3);

output_low(pin_d7);

              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc," VOL SYNC FAIL  ");
              lcd_gotoxy(1,2);
              printf(lcd_putc,"****LOAD OFF****");
              delay_ms(100);
output_high(pin_d1);
  delay_ms(100);
   
   
             
        }
        
   else if((freq>55)||(freq<45))
        {
      output_low(pin_d2);
output_high(pin_d3);

output_low(pin_d7);

              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc," FREQ SYNC FAIL ");
              lcd_gotoxy(1,2);
              printf(lcd_putc,"****LOAD OFF****");
              delay_ms(100);
  output_high(pin_d1);
  delay_ms(100);
             
        }
        
    
  else 
   {
   output_low(pin_d1);
    output_high(pin_d2);
output_low(pin_d3);

output_high(pin_d7);

    printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"SYSTEM IS NORMAL");
              lcd_gotoxy(1,2);
              printf(lcd_putc,"V:%u",vol);
              lcd_gotoxy(8,2);
              printf(lcd_putc,"F:%u",freq);
              delay_ms(10);
              
   
   }
    
            
           
    } //while loop
}  //main loop

