/*
TITLE: SOIL BASED IRRIGATION SYSTEM USIGN MC
A0= WATER LOW LEVEL,
A1= WATER MIDDLE LEVEL,
A2= WATER HIGH LEVEL,

3 LEDS= C4,C5,C6,
C7 = RELAY1 
*/
#include <16F72.h>           //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use delay  (clock=20000000)

void main()
{
  unsigned int l1,l2,l3;
    
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );
     
//MC HEALTH CHECK UP   
   output_high(pin_C4);output_high(pin_C5); output_high(pin_C6);
   delay_ms(500);
   output_low(pin_C4); output_low(pin_C5); output_low(pin_C6);
   delay_ms(500);
   output_high(pin_C4);output_high(pin_C5); output_high(pin_C6);
   delay_ms(500);
   output_low(pin_C4); output_low(pin_C5); output_low(pin_C6);
   delay_ms(500);
 
      while(true)
     {
      set_adc_channel(0);                           
      delay_ms(1);
      l1=read_adc(); 
      delay_ms(1);
      
        set_adc_channel(3);                           
      delay_ms(1);
      l2=read_adc(); 
      delay_ms(1);
      
        set_adc_channel(2);                           
      delay_ms(1);
      l3=read_adc(); 
      delay_ms(1);
      //convert adc to temp
     
   
      
 ///////////////////////////////////////////////////
 //1st if tank is full
  if((l1>=50)&&(l2>=50)&&(l3>=50))  //soil is wet
  {
        output_low(pin_c7);  //relay off
        output_high(pin_c4); output_high(pin_c5);output_high(pin_c6); 
    
  
  }
  //if tank is empty
  else if((l1<=50)&&(l2<=50)&&(l3<=50))
  {
        output_high(pin_c7);  //relay off
        output_low(pin_c4); output_low(pin_c5);output_low(pin_c6); 

  }
  
  else
  {
  output_high(pin_c7);//relay on
  
  
  // all levels indications
    if(l1>50)
  {
    output_high(pin_c4);
  }
  
  
  if(l2>50)
  {
    output_high(pin_c5);
  }
  
  
  if(l3>50)
  {
    output_high(pin_c6);
  }
  
  //output_high(pin_c4); output_(pin_c5);output_low(pin_c6); 
 delay_ms(500);
        
  }
   
      }
}
    




