/*
TITLRE: GSM BASED POWER THEFT ALERT USING GSM WITH CT
PIC16F73,
A0=  CT,
C1= ENERGY METER OPTO COUPLER,
C1= ENERGYMETER,
B0,B1=  GSM,
B2 TO B7 = LCD,
C3= BUZZER,
C4= GREEN LED,
 C5 = RED LED,
 C7 =RELAY
 
*/

#include <16F877A.h>
#fuses HS,NOWDT,PROTECT,brownout,put
#use  delay  (clock=20000000) //crystall oscillator 
#include "flex_lcd.c"
#include "dc_motor.c" 

void main()
{
    unsigned int16 value=0;
   lcd_init();  
  
   lcd_putc('\f');         //Clear LCD 
   lcd_gotoxy(1,1);
   printf(lcd_putc,"WIRELESS POWER\n");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"THEFT MONITORING\n");
   delay_ms(1000);
    
   
   output_high(PIN_D2);
    output_high(PIN_D3);    
    output_high(PIN_C5);
    output_high(PIN_C4);
    delay_ms(500);   
    output_low(PIN_D2);
    output_low(PIN_D3);    
    output_low(PIN_C5);
    output_low(PIN_C4);
    delay_ms(500);
    output_high(PIN_D2);
    output_high(PIN_D3);    
    output_high(PIN_C5);
    output_high(PIN_C4);
    delay_ms(500);   
    output_low(PIN_D2);
    output_low(PIN_D3);    
    output_low(PIN_C5);
    output_low(PIN_C4);
     
   output_high(PIN_b4);
    output_high(PIN_b3); 
   
           M1_ON(0,1);                          //Left
           M2_ON(1,0); 
  delay_ms(2000);
       M1_ON(0,0);                          //Left
         M2_ON(0,0); 
 
  output_high(PIN_D2);
    output_high(PIN_D3);    
    output_high(PIN_C5);
    output_high(PIN_C4);
    delay_ms(500);   
    output_low(PIN_D2);
    output_low(PIN_D3);    
    output_low(PIN_C5);
    output_low(PIN_C4);
    
   while(true)
   {
          
       set_timer1(0);   
      setup_timer_1(t1_external | T1_DIV_BY_1);//c0
      output_low(pin_d2);
      delay_ms(3000);         
         //setup_timer_1(T1_DISABLED);
      value=get_timer1();
       value=value+1;
       //value=value*10;
            printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"count=%LU",value); 
     delay_ms(500);
     output_high(pin_d2);
     

     
             //RIGHT
       if(value==5)
         {
            
   output_high(PIN_b4);
    output_high(PIN_b3);
           output_high(pin_C5);
           M1_ON(0,1);                          //Left
           M2_ON(1,0);           
           delay_ms(700);
           output_low(PIN_C5);
          
         }
         
            
          //LEFT  
     else if(value==4)
         {
            
   output_high(PIN_b4);
    output_high(PIN_b3);
           output_high(pin_C4);
           M1_ON(1,0);                          //Left
           M2_ON(0,1);           
           delay_ms(700);
           output_low(PIN_C4);
          
         }
         
          //BACKWARD  
      else if(value==3)
         {
            
   output_high(PIN_b4);
    output_high(PIN_b3);
           output_high(pin_D3);
           M1_ON(0,1);                          //Left
           M2_ON(0,1);           
           delay_ms(2000);
           output_low(PIN_D3);
          
         }
     
          
     //FORWARD
        else if(value==2)
         {
            
   output_high(PIN_b4);
    output_high(PIN_b3);
           output_high(pin_D2);
           M1_ON(1,0);                          //Left
           M2_ON(1,0);           
           delay_ms(2000);
           output_low(PIN_D2);
         }
        
         //STOP
      // if(value==1)
       else  {
           output_low(PIN_d2);  output_low(PIN_d3);  output_low(PIN_C4);  output_low(PIN_C5);
           M1_ON(0,0);                          //Left
           M2_ON(0,0);           
           delay_ms(100);
          
          
         }
         
     /*
     
     if(value==2)
     {
     output_high(pin_d2);delay_ms(1000);  output_low(pin_d2);
     }
     
       if(value==3)
     {
     output_high(pin_d3);delay_ms(1000);  output_low(pin_d3);
     }
    
       if(value==4)
     {
     output_high(pin_c4);delay_ms(1000);  output_low(pin_c4);
     }
    
       if(value==5)
     {
     output_high(pin_c5);delay_ms(1000);  output_low(pin_c5);
     }
     */
    
     
   } //WHILE LOOP 
}
    






