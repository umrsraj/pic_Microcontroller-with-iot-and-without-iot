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

#include <16F877A.h> //miceocontroller name
#fuses HS,NOWDT,PROTECT,brownout,put
#use  delay(clock=20000000) //crystall oscillator 
#include "flex_lcd.c"
#include "dc_motor.c" 

void beep()
{
    output_high(PIN_b0);
    delay_ms(1000);
    output_low(PIN_b0);
    delay_ms(500);
    
}

void main()
{
    unsigned int16 value=0;
   lcd_init();  
  
   lcd_putc('\f');         //Clear LCD 
   lcd_gotoxy(1,1);
   printf(lcd_putc,"EYE BLINK \n");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"WHEEL CHAIR\n");
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
     
   // output_high(PIN_b4);
    //output_high(PIN_b3); 
   
 //          M1_ON(0,1);                          //Left
   //        M2_ON(1,0); 
 // delay_ms(2000);
     //  M1_ON(0,0);                          //Left
       //  M2_ON(0,0); 
 /*
 output_high(PIN_D7); output_low(PIN_D6); 
 output_high(PIN_D5); output_low(PIN_d4);
 delay_ms(2000);
 output_low(PIN_D7); output_low(PIN_D6); 
 output_low(PIN_D5); output_low(PIN_d4);
 */
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
      printf(lcd_putc,"Count=%LU",value); 
     delay_ms(500);
     output_high(pin_d2);
     

     
             //RIGHT
       if(value==2)
         {
            
   
           output_high(pin_d2);
         //  M1_ON(0,1);                          //Left
           //M2_ON(1,0); 
           
output_low(PIN_D7); output_high(PIN_D6); 
 output_high(PIN_D5); output_low(PIN_D4);
       lcd_gotoxy(5,2);
      printf(lcd_putc,"FWD"); 
            delay_ms(2000);
           output_low(PIN_d2);
          
         }
         
            
          //LEFT  
     else if(value==3)
         {
            
   //output_high(PIN_b4);
    //output_high(PIN_b3);
           output_high(pin_d3);
          // M1_ON(1,0);                          //Left
           //M2_ON(0,1);     
  output_high(PIN_D7); output_low(PIN_D6); 
 output_low(PIN_D5); output_high(PIN_D4);
  lcd_gotoxy(5,2);
      printf(lcd_putc,"BWD"); 
          delay_ms(2000);
           output_low(PIN_d3);
          
         }
         
          //BACKWARD  
      else if(value==4)
         {
           output_high(pin_c4);
           //M1_ON(0,1);                          //Left
           //M2_ON(0,1);     
 output_high(PIN_D6); output_low(PIN_D7); 
 output_high(PIN_d4); output_low(PIN_D5);
  lcd_gotoxy(5,2);
      printf(lcd_putc,"LFT"); 
           delay_ms(2000);
           output_low(PIN_c4);
          
         }
     
          
     //FORWARD
        else if(value==5)
         {
            
   //output_high(PIN_b4);
    //output_high(PIN_b3);
           output_high(pin_c5);
          // M1_ON(1,0);                          //Left
           //M2_ON(1,0);
 output_high(PIN_D7); output_low(PIN_D6); 
 output_high(PIN_D5); output_low(PIN_d4);
       lcd_gotoxy(5,2);
      printf(lcd_putc,"RGT"); 
           delay_ms(2000);
           output_low(PIN_c5);
         }
        
         //STOP
      // if(value==1)
       else  {
           output_low(PIN_d2);  output_low(PIN_d3);  output_low(PIN_C4);  output_low(PIN_C5);
          // M1_ON(0,0);                          //Left
           //M2_ON(0,0);  
            output_low(PIN_D7);  output_low(PIN_D6);  output_low(PIN_D5);  output_low(PIN_d4); 
      lcd_gotoxy(5,2);
      printf(lcd_putc,"STP"); 
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
    






