
#include <16f877a.h>
#fuses HS,PUT, PROTECT, NOWDT
#use delay(clock=20M)

void main()
{
   int data;
   int soil;
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );
   
   output_high(pin_d2);
   delay_ms(500);
   output_low(pin_D2);
   delay_ms(500);

   output_high(pin_d2);
   delay_ms(500);
   output_low(pin_D2);
   delay_ms(500);
   
   
   while(1)
   {

      set_adc_channel(0);                           
      delay_ms(1);
      soil=read_adc(); 
      delay_ms(1);


      if(input(pin_b4))            //checking for DTMF availability through steering output pin
      {
      data=input_b();
      data=data & (0x0F);             //reading first 4 pins data b0-b3 
      
     output_high(pin_D2); 
     delay_ms(500);
     output_low(pin_d2);
     
      set_adc_channel(0);                           
      delay_ms(1);
      soil=read_adc(); 
      delay_ms(1);
      switch (data)
         {
              case 2:
                if(soil<180)  //oil is wet
              {
                output_high(pin_D2);                 //LED 1 ON
                output_high(pin_D7);                 //D1 ON
                 output_high(pin_D6);     
               
              }
              else
              {
               output_low(pin_D2);                 //LED 1 OFF
               output_low(pin_D7);                // D1 OFF
                 output_low(pin_D6); 
                 }
                        
               break;
               
               
         case 8:output_low(pin_D2);                 //LED 1 OFF
               output_low(pin_D7);                // D1 OFF
               
               break;
         
               
        
      }
        }
     
   if(soil>180)   
              {
               output_low(pin_D2);                 //LED 1 OFF
               output_low(pin_D7);                // D1 OFF
                 output_low(pin_D7); 
                }
  
                  
   }
}





