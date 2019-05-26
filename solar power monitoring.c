/******************************************************************************************
TITLE: SOLAR POWER MONITORING SYSTEM
PIC16F877a,

TEMPERATURE = A0
LDR = A1
VOLTAGE DIVIDER FOR VOLTAGE = A2
VOLTAGE DIVIDER FOR CURRENT = A3
LCD = B PORT

G LED = d2
R LED = d3

*******************************************************************************************/
#include <16f877A.h>
#fuses HS,PUT,NOWDT,NOPROTECT
#use delay(clock=20000000)
//#define ADC=8
#include "flex_lcd.c"

      /*
  float read_battery_voltage()
{   
   float value1;
   float value2;
   float value3;
   unsigned long final;
   float vol_final;
   float vol;
   //float temp = 0;
   set_adc_channel(2);
   delay_ms(10);
   value1 = Read_ADC();
   delay_ms(100);
   value2 = Read_ADC();
   delay_ms(100);
   value3 = Read_ADC();
   final = (value1 + value2 + value3)/3.0;
   vol = ((final*5.0)/255.0) * 6.0; //It works for 20 volts pannel (dont know why) (Trial and Error method)   
   return vol;   
}
    
         
  float read_battery_voltage1()
{   
   float value11;
   float value21;
   float value31;
   unsigned long final1;
   float vol_final1;
   float vol1;
   //float temp = 0;
   set_adc_channel(3);
   delay_ms(10);
   value11 = Read_ADC();
   delay_ms(100);
   value21 = Read_ADC();
   delay_ms(100);
   value31 = Read_ADC();
   final1 = (value11 + value21 + value31)/3.0;
   vol1 = ((final1*5.0)/255.0) * 6.0; //It works for 20 volts pannel (dont know why) (Trial and Error method)   
   return vol1;   
}
    
*/





void main() 
{

float temp1,temp2;
unsigned int ldr = 0;
unsigned int voltage = 0;
float v = 0;
 float c = 0.0;
 float current = 0.0;
  unsigned long vol_read;
   unsigned long vol_read1;
 
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
   
   
   
           output_low(pin_D0); 
            output_low(pin_D1);
     
  //display initial messsage ....................................
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"AUTOMAIC RAILWAY");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"GATE CNTRL S/M");
              delay_ms(1500);
           
    while(TRUE)
    {
   // vol_read = read_battery_voltage();
    
   // vol_read1 = read_battery_voltage1();
    
         set_adc_channel(0);       //TEMPERATURE ............................                      
      delay_ms(1);
      temp2=read_adc(); 
      delay_ms(1);
      temp1 = (temp2 * 100)/256;
      temp1 = temp1 * 5;
        
        
      set_adc_channel(1);
      delay_ms(50);// delay built-in function call
      ldr = Read_ADC();                   // A/D read functions- built-in         
             
        set_adc_channel(2);
      delay_ms(50);// delay built-in function call
      voltage = Read_ADC();                   // A/D read functions- built-in         
             
       set_adc_channel(3);
      delay_ms(50);// delay built-in function call
      c = Read_ADC();                   // A/D read functions- built-in         
             
     // voltage = (voltage/51)+3;
           /////////////   mapping  ///////////////////////////////////////////
           v = (voltage - 0) * ((5-0) / ((255 - 0) + 0)) ;
           
           
        ////////////  mapping  ///////////////////////////////////////
     
      
      current = (c/772.73)+0.18;
      
       printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"T = %2.0f",temp1);
              
               lcd_gotoxy(9,1);
              printf(lcd_putc,"L =%u",ldr);
     
        lcd_gotoxy(0,2);
              printf(lcd_putc,"V =  %1.1f",v);
               lcd_gotoxy(9,2);
              printf(lcd_putc,"I =  %0.2f",current);
      delay_ms(100);
      
      
      
      
        
           
    } //while loop
}  //main loop

