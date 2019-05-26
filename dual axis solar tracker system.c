
/******************************************************************************
TITLE:AUTOMATIC VEHICLE PARKING SYSTEM WITH MC
      GATE ENTRANCE AND EXIT
PIC16F877A MC
A0 = ENTRANCE LDR SENSOR
A1 = EXIST LDR SENSOR

A2 = SLOT 1,
A3 = SLOT 2,
A4 = SLOT 3,
A5 = SLOT 4,

LCD= B2 TO B7
DC MOTOR DRIVER (L293D) =C0 TO GND,
D2= GREEN LED,
D3 = RED LED, 
*******************************************************************************/
#include <16F877A.h>           //Microcontroller Used    pic16f877a 40pin size
#fuses      HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include "dc_motor.c"    //dc motor header file
#include "flex_lcd.c"

void main()
{

   int LDR1,LDR2,LDR3,LDR4;
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG ); 
  

  
     lcd_init();
          
       printf(lcd_putc,"\f");
      lcd_gotoxy(0,1);
      printf(lcd_putc,"DUAL AXIS SOLAR ");
      
      lcd_gotoxy(0,2);
      printf(lcd_putc,"TRACING SYSTEM");
      lcd_gotoxy(1,2);
      delay_ms(2000);
      /*
        printf(lcd_putc,"\f");
      lcd_gotoxy(4,1);
      printf(lcd_putc," BY UCE&T, ");
      
      lcd_gotoxy(3,2);
      printf(lcd_putc,"MG UNIVERSITY ");
      lcd_gotoxy(1,2);
      delay_ms(2000);
     */
   
  //health check up
    output_high(PIN_D2);
    output_high(PIN_D3);  
    output_high(PIN_C4);
    output_high(PIN_C5);  
      output_high(PIN_C6);
    delay_ms(500);   
    output_low(PIN_D2);
    output_low(PIN_D3);  
    output_low(PIN_C4);
    output_low(PIN_C5); 
      output_low(PIN_C6);
    delay_ms(500);
   output_high(PIN_D2);
    output_high(PIN_D3);  
    output_high(PIN_C4);
    output_high(PIN_C5); 
      output_high(PIN_C6);
    delay_ms(500);   
    output_low(PIN_D2);
    output_low(PIN_D3);  
    output_low(PIN_C4);
    output_low(PIN_C5);
     output_low(PIN_C6);
    delay_ms(500);
   
  //CONTINOUS LOOP..........................
   while(1)
   {      
         
    
      set_adc_channel(0);      //GAS LEAKAGE.................................                     
      delay_ms(1);
      LDR1=read_adc(); 
      
       
      set_adc_channel(1);      //GAS LEAKAGE.................................                     
      delay_ms(1);
      LDR2=read_adc(); 
      
       
      set_adc_channel(2);      //GAS LEAKAGE.................................                     
      delay_ms(1);
      LDR3=read_adc(); 
      
       
      set_adc_channel(3);      //GAS LEAKAGE.................................                     
      delay_ms(1);
      LDR4=read_adc(); 
      
      
      
      
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"L1=%u",LDR1);
      
      lcd_gotoxy(8,1);
      printf(lcd_putc,"L2=%u",LDR2);
      lcd_gotoxy(1,2);
      
       lcd_gotoxy(1,2);
      printf(lcd_putc,"L3=%u",LDR3);  
     
     lcd_gotoxy(8,2);
      printf(lcd_putc,"L4=%u",LDR4);  
      
         delay_ms(10);
        
    
  if(LDR1<70)
  {
    M1_ON(1,0);
    output_high(PIN_D2);  
    delay_ms(200);   
    output_low(PIN_D2);
    M1_ON(0,0);
   }
   
   
       
  else if(LDR2<70)
  {
    M1_ON(0,1);
    output_high(PIN_D3);  
    delay_ms(200);   
    output_low(PIN_D3);
    M1_ON(0,0);
   }
    else
  { 
    delay_ms(200);
    M2_ON(0,0);
    M1_ON(0,0);
    delay_ms(200);   
    output_low(PIN_D2);
    output_low(PIN_D3);
    output_low(PIN_C4);
    output_low(PIN_C5);
   
   }   
     
     
         
  if(LDR3<70)
  {
    M2_ON(1,0);
    output_high(PIN_C4); //output_high(PIN_C5); 
    delay_ms(200);   
    output_low(PIN_C4); //output_low(PIN_C5);
    M1_ON(0,0);
   }
     
         
  else if(LDR4<70)
  {
    M2_ON(0,1);
    output_high(PIN_C5);  
    delay_ms(200);   
    output_low(PIN_C5);
    M1_ON(0,0);
   }
    
         
  else
  { 
    delay_ms(200);
    M2_ON(0,0);
    M1_ON(0,0);
    delay_ms(200);   
    output_low(PIN_D2);
    output_low(PIN_D3);
    output_low(PIN_C4);
    output_low(PIN_C5);
      output_low(PIN_C6);
   
   }  
  
 
   
   }  //while close
     
   }  //main close

