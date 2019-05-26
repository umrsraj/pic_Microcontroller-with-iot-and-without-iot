
/*******************************************************************************************************************************************
Project Title: AUTOMATIC RAILWAY GATE CONTROL SYSTEM
16F877A, DC motors, D2(GREEN), D3(RED), ---LED, A0(IN),A1(OUT)= IR SENSORS , 
******************************************************************************************************************************************/
#include <16F877A.h>           //Microcontroller Used   
#fuses HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include "dc_motor.c"
#include "flex_lcd.c"

void beep()
{
 output_high(PIN_d1);delay_ms(1000);
  output_low(PIN_d1);delay_ms(1000);
 output_high(PIN_d1);delay_ms(1000);
  output_low(PIN_d1);delay_ms(1000);


}



void main()
{
  unsigned int ir1,ir2;
    
    lcd_init();
    setup_port_a( ALL_ANALOG );
   setup_adc(ADC_CLOCK_INTERNAL);
   
   lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"AUTOMATIC RAILWAY   ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"GATE CONTROL SYSTEM");
   delay_ms(1500);      
    
    output_high(PIN_D2);
    output_high(PIN_D3);    
    delay_ms(500);   
    output_low(PIN_D2);
    output_low(PIN_D3);    
    delay_ms(500);
    output_high(PIN_D2);
    output_high(PIN_D3);    
    delay_ms(500);   
    output_low(PIN_D2);
    output_low(PIN_D3);    
    delay_ms(500);
    
    
   while(1)
   {
        set_adc_channel(0);
         delay_ms(10);
         ir1 = Read_ADC();   //read ldr adc value
      
       set_adc_channel(1);
         delay_ms(10);
         ir2 = Read_ADC();   //read ldr adc value
   /*
    lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"ir1= %u ",ir1);
   lcd_gotoxy(0,2);
   printf(lcd_putc,"ir2= %u ",ir2);
   delay_ms(1500);   
   */
   
    //  if(input(pin_a0))            //AO ==1  IN SENSOR
     if(ir1>50)
     {
          output_high(PIN_D3);
          output_low(PIN_D2);
   lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"TRAIN COMING......   ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"<<<-----------<");
          beep();         //MOTOR ON
          output_low(PIN_c2);
          output_high(PIN_c1);
               delay_ms(300); 
     output_low(PIN_c1);
     output_low(PIN_c2);               
               /*   M1_ON(0,1);                          //Forward
                    M2_ON(0,1);
                    delay_ms(1500);
                    M1_ON(0,0);                          //stop
                    M2_ON(0,0);
                    delay_ms(100);
  
      */
          

   lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"GATE CLOSING......   ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"<<<-----------<");
      delay_ms(1500); 
      
       
}   
          
 //if(input(pin_a1))            //A1 ==0  IN SENSOR
 if(ir2>50)
 {
          output_high(PIN_D3);
          output_low(PIN_D2);
   lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"TRAIN LEAVING......   ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,">----------->>>");
  beep();
    output_low(PIN_c1);
    output_high(PIN_c2);    
        delay_ms(300); 
     output_low(PIN_c1);
     output_low(PIN_c2);  
   lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(0,1);
   printf(lcd_putc,"GATE OPENING......   ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"<<<-----------<");
    delay_ms(1500); 
    
                   
 }   
  
 if((ir1<50)&&(ir2<50))
 {
  output_low(PIN_c2);
  output_low(PIN_c1);
  
  output_high(PIN_d2);
  output_low(PIN_d3); 
 }
       
   }
}
                          
                 
                 


