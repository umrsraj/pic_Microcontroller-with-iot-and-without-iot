/******************************************************************************************
TITLE: AUTOMATIC CAR PARKING SYSTEM USING LDR 
PIC16F877A
LCD= B2 TO B7
A0= SLOT 1
A1= SLOT 2
A0= SLOT 3
A1= SLOT 4

D2= GREEN LED,
D3= RED LED.
*******************************************************************************************/
#include <16F877a.h>  //MC
#FUSES HS,PUT
#use delay(clock=20M)
#include "flex_lcd.c"   //LCD Driver



void main()
{
  unsigned int ldr1,ldr2;   
  unsigned int ldr3,ldr4; 
  //HEALTH CHECK................................
output_high(pin_d2);  //LED ON
output_high(pin_d3);  //LED2 ON
delay_ms(1000);  //1SEC
output_low(pin_d2);  //LED OFF
output_low(pin_d3);
delay_ms(1000);
output_high(pin_d2);  //LED ON
output_high(pin_d3);  //LED2 ON
delay_ms(1000);  //1SEC
output_low(pin_d2);  //LED OFF
output_low(pin_d3);
delay_ms(1000);
   setup_port_a( ALL_ANALOG );
   setup_adc(ADC_CLOCK_INTERNAL);
    
lcd_init();
 //display initial messsage ....................................
              printf(lcd_putc,"\f");  //LCD DATA CLEAAR
              lcd_gotoxy(3,1);   //COL AND ROW 
              printf(lcd_putc,"CAR PARKING ");
              lcd_gotoxy(4,2);
              printf(lcd_putc,"SYSTEM ");
              delay_ms(2000);
          
    
   
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"S1 :");
              lcd_gotoxy(9,1);
              printf(lcd_putc,"S2 :");
              
              lcd_gotoxy(0,2);
              printf(lcd_putc,"S3 :");
              lcd_gotoxy(9,2);
              printf(lcd_putc,"S4 :");
              delay_ms(200);
  
   //INFINITE LOOP...........................................................................................
    while(TRUE)
    {
 //LDR PERCENTAGE.................... 
         set_adc_channel(0);
         delay_ms(10);
         ldr1 = Read_ADC();   //read ldr adc value
      
         set_adc_channel(1);
         delay_ms(10);
         ldr2 = Read_ADC();   //read ldr adc value
         
          set_adc_channel(2);
         delay_ms(10);
         ldr3 = Read_ADC();   //read ldr adc value
         
          set_adc_channel(7);
         delay_ms(10);
         ldr4 = Read_ADC();   //read ldr adc value

      /*
           printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"%u",ldr1);
                 lcd_gotoxy(6,1);
                  printf(lcd_putc,"%u",ldr2);
              printf(lcd_putc,"S1 :");
              
                lcd_gotoxy(0,2);
              printf(lcd_putc,"%u",ldr3);
                 lcd_gotoxy(6,2);
                  printf(lcd_putc,"%u",ldr4);
              printf(lcd_putc,"S1 :");
              delay_ms(1500);
                    
      */
      
         
//increment................................................           
          // if(input(pin_a0))  //A0==1
            if(ldr1>150)  //A0==1
            {
              output_high(pin_d2);output_low(pin_d3);
              lcd_gotoxy(5,1);
              printf(lcd_putc,"1");
             delay_ms(500);
             }
           //if(!input(pin_a0))  //A0==1
           if(ldr1<150)
           {
             
              output_high(pin_d2);output_low(pin_d3);
              lcd_gotoxy(5,1);
              printf(lcd_putc,"0");
             delay_ms(500);
             }
           
            
           
             //SLOT2
            //  if(input(pin_a1))  //
           if(ldr2>150)
           {     output_high(pin_d2);output_low(pin_d3);
              lcd_gotoxy(14,1);
              printf(lcd_putc,"1");
             delay_ms(500);
             }
           // if(!input(pin_a1))  //
           if(ldr2<150)
          {     output_high(pin_d2);output_low(pin_d3);
              lcd_gotoxy(14,1);
              printf(lcd_putc,"0");
             delay_ms(500);
             }  
             
             
//SLOT3          
          // if(input(pin_a2))  //A0==1
            if(ldr3>150)
            {
             
              output_high(pin_d2);output_low(pin_d3);
              lcd_gotoxy(5,2);
              printf(lcd_putc,"1");
             delay_ms(500);
             }
          // if(!input(pin_a2))  //A0==1
            if(ldr3<150)
            {
             
              output_high(pin_d2);output_low(pin_d3);
              lcd_gotoxy(5,2);
              printf(lcd_putc,"0");
             delay_ms(500);
             }
           
           
                    
             //SLOT4
            //  if(input(pin_a3))  //
           if(ldr4>150)
          {     output_high(pin_d2);output_low(pin_d3);
              lcd_gotoxy(14,2);
              printf(lcd_putc,"1");
             delay_ms(500);
             }
           //  if(!input(pin_a3))  //
            if(ldr4<150)
           {     output_high(pin_d2); output_low(pin_d3);
              lcd_gotoxy(14,2);
              printf(lcd_putc,"0");
             delay_ms(500);
             }
              
               
            //if((input(pin_a0))&&(input(pin_a1))&&(input(pin_a2))&&(input(pin_a3)))
              
               if((ldr1<150)&&(ldr2<150)&&(ldr3<150)&&(ldr4<150))
              
              {
               output_low(pin_d2);output_high(pin_d3);
                          
              }
                    
           
  } //while loop
}  //main loop


