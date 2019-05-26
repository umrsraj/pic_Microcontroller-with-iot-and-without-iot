

#include <16F73.h>           //Microcontroller Used
#fuses HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency

void main()
{
unsigned int ir=0;
unsigned int k=0;
  
   unsigned int adc_value1;
    
  
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG ); 
   
  
   output_high(pin_C4);       // Health check
   output_high(pin_C5); 
   delay_ms(500);
   output_low(pin_C4);
   output_low(pin_C5);
   delay_ms(500); 
        
   output_high(pin_C4);       // Health check
   output_high(pin_C5); 
   delay_ms(500);
   output_low(pin_C4);
   output_low(pin_C5);
   delay_ms(500); 
    
 
   while(true)
   {
        
      set_adc_channel(0);                           
      delay_ms(1);
      adc_value1=read_adc(); 
      
  
      set_adc_channel(2);                           
      delay_ms(1);
      ir=read_adc(); 

 
   
 //  1st sensor bridge damage detection
 if(adc_value1>150)   
  {
 
    output_low(pin_b0);       // Health check
   output_high(pin_b1);
   
   output_low(pin_C4);       // Health check
   output_high(pin_C5);  
      
   
 
   output_high(pin_b0);       // Health check
   output_high(pin_b1);

  delay_ms(1000);
  
  }
  
//track fault detection .........   
  if(ir<70) 
  {
  //rf
   output_low(pin_b0);       // Health check
   output_high(pin_b2);
    
   output_low(pin_C4);       // Health check
   output_high(pin_C5);  
   
     
   output_high(pin_b0);       // Health check
   output_high(pin_b2);
   
  //  beep();
   delay_ms(1000);
   
 }
 
 //else
 {
 
   output_high(pin_C4);       // Health check
   output_low(pin_C5); 
      delay_ms(100);
      output_high(pin_b0);
     
 
 }
 
 
   } //while loop
}
    






