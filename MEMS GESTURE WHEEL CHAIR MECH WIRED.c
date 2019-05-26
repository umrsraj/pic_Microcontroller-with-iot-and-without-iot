/*
MEMS WHEEL CHAIR WHTH WIRED

TWO RELAY LT MTR DRIVER= C7,C6
TWO RELAY RT MTR DRIVER= C7,C6

LCD -CHECKING
C0,C1,C2,C3= 4 LED'S
MEMS =A0,A1


*/

 

#include <16F73.h>           //Microcontroller Used
#fuses      HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include <flex_lcd.c>

void main()
{
   unsigned int x=0,y=0;
   
    output_high(PIN_c0);
    output_high(PIN_c1);    
    output_high(PIN_C2);
    output_high(PIN_C3);
    delay_ms(500);   
    output_low(PIN_c0);
    output_low(PIN_c1);    
    output_low(PIN_C2);
    output_low(PIN_C3);
    delay_ms(500);
    output_high(PIN_c0);
    output_high(PIN_c1);    
    output_high(PIN_C2);
    output_high(PIN_C3);
    delay_ms(500);   
    output_low(PIN_c0);
    output_low(PIN_c1);    
    output_low(PIN_C2);
    output_low(PIN_C3);
    delay_ms(500);
    
     setup_adc(ADC_CLOCK_INTERNAL);                             // SETTING UP ADC                  
     setup_adc_ports(ALL_ANALOG);  
     lcd_init(); 
    
   while(1)
   {
      set_adc_channel(0);                           
      delay_ms(10);
      x=read_adc(); 
      delay_ms(1);
      
      set_adc_channel(1);                           
      delay_ms(10);
      y=read_adc();
      delay_ms(1);
      
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"x:%u ",x);
      printf(lcd_putc,"y:%u ",y);
      delay_ms(500);
     
    //forward
      if(x<70)
      {
        output_high(pin_c0);                 //LED 1 ON
         //motor driver
        output_high(pin_b1); output_low(pin_b0);    //1,0
        output_high(pin_c5); output_low(pin_c4);   //1,0
         delay_ms(100);
         //output_low(pin_c0); 
      }
      
      //backward
      else if(x>95)  //100
      {
            
         output_high(pin_c1);                 //LED 1 ON
         //motor driver
        output_low(pin_b1); output_high(pin_b0);    //1,0
        output_low(pin_c5); output_high(pin_c4);   //1,0
         delay_ms(100);
         //output_low(pin_c1); 
      }
      
      //left 
      else if(y<70)
      {
          output_high(pin_c2);                 //LED 1 ON
         //motor driver
        output_high(pin_b1); output_low(pin_b0);    //1,0
        output_low(pin_c5); output_high(pin_c4);   //1,0
         delay_ms(100);
         //output_low(pin_c2); 
      }
      
      else if(y>95)  //90
      {
        
          output_high(pin_c3);                 //LED 1 ON
         //motor driver
        output_low(pin_b1); output_high(pin_b0);    //1,0
        output_high(pin_c5); output_low(pin_c4);   //1,0
         delay_ms(100);
        // output_low(pin_c3); 
      }
      
      else
      {          
          output_low(PIN_c0);
          output_low(PIN_c1);    
          output_low(PIN_c2);
          output_low(PIN_C3);
         output_low(pin_b1); output_low(pin_b0);    //1,0
        output_low(pin_c5); output_low(pin_c4);   //1,0
        delay_ms(200);
      }

      
   }
}
                          
                           
                        
                  



