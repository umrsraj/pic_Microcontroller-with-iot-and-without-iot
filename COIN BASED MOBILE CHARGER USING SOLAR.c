/******************************************************************************************
TITLE: COIN BASED MOBILE CHARGER WITH AUTO POWER MODE CHANGING
PIC16F877A,

AC INPUT REF= A0,
IR SENSOR= D1,
D2= BREEN LED,
D3= RED LED.
D0= BUZZER,
C7 =RELAY

*******************************************************************************************/
#include <16F877A.h>
#FUSES HS,PUT
#use delay(clock=20M)
#include <flex_lcd.c>

int flag=0;


void beep()
{
output_high(pin_d1);
   delay_ms(500);
output_low(pin_d1);
 delay_ms(500);
}

#INT_EXT
void ext_isr(void)
{
  flag=1;
  
 }





void main() 
{


  float battery,pizeo;
   lcd_init();
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );
   
    // ext_int_edge(H_TO_L);       // Interrupt on falling edge of RB0/INT pin
  ext_int_edge(L_TO_H);       // Interrupt on falling edge of RB0/INT pin
  clear_interrupt(INT_EXT);   // Clear RB0/INT external interrupt flag bit
  enable_interrupts(INT_EXT); // Enable RB0/INT external interrupt
  enable_interrupts(GLOBAL);  // Enable all unmasked interrupt
   
   
output_high(pin_d2);
output_high(pin_d3);
   delay_ms(1000);
output_low(pin_d2);
output_low(pin_d3);
output_high(pin_d2);
output_high(pin_d3);
   delay_ms(1000);
output_low(pin_d2);
output_low(pin_d3);
 beep();  
           output_low(pin_d6);  //RELAY ON
     
  //display initial messsage ....................................
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"COIN BASED MOBILE ");
              lcd_gotoxy(3,2);
              printf(lcd_putc,"CHARGER USING  ");
              delay_ms(2000);
              
             printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"  HYBRID POWER ");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"SOLAR &AC MAINS");
              delay_ms(2000);
              
                
             printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"BY>-->>GOMATHI,");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"VINITHA & VIVEK");
              delay_ms(6000);
              
          output_high(pin_d6);  //RELAY2 for charging 
           
    while(TRUE)
    {
        
      set_adc_channel(0);
      delay_ms(50);// delay built-in function call
      battery = Read_ADC();                   // A/D read functions- built-in         
      battery=battery*125/1023;
       
      /*
      set_adc_channel(1);
      delay_ms(50);// delay built-in function call
      pizeo = Read_ADC();*                  // A/D read functions- built-in
      
      lcd_putc("\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"voltage:%f ",battery);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"pizeo:%f volts ",pizeo);
      delay_ms(500);
      
      */
      
      
        if(battery>15)
        {
        beep();beep();output_high(pin_d2);
        output_low(pin_d7);  //RELAY ON
         output_low(pin_d6);  //RELAY ON
              printf(lcd_putc,"\f");
              lcd_gotoxy(3,1);
              printf(lcd_putc,"BATTERY HIGH ");
              lcd_gotoxy(1,2);
              printf(lcd_putc,"  Voltage:%f ",battery);
              delay_ms(1000);
              output_low(pin_d2);
        }
        
        else{
          
        if(battery<7)
        {
              beep();output_high(pin_d2);
              output_low(pin_d7);  //RELAY ON
              printf(lcd_putc,"\f");
              lcd_gotoxy(3,1);
              printf(lcd_putc,"BATTERY LOW ");
              lcd_gotoxy(1,2);
              printf(lcd_putc,"  Voltage:%f ",battery);
              delay_ms(1000);
              output_low(pin_d2);
        
        }
        
              
        }
     // if((input(pin_D0)))   //IF IR SENSOR DETECT
       if(flag==1)  
       {
        beep();
        output_high(pin_d2);  //GREEN LED ON
           output_low(pin_d3);  //RED LED OFF
           output_high(pin_d7);  //RELAY ON
           
             printf(lcd_putc,"\f");
              lcd_gotoxy(1,1);
              printf(lcd_putc,"MOBILE CHARGING... ");
              lcd_gotoxy(3,2);
              printf(lcd_putc," STARTED... ");
              
           delay_ms(60000); //delay_ms(60000); delay_ms(60000); //delay_ms(60000);delay_ms(60000);    
           //delay_ms(60000); delay_ms(60000); delay_ms(60000); delay_ms(60000);delay_ms(60000);
           // delay_ms(60000); delay_ms(60000); delay_ms(60000); delay_ms(60000);delay_ms(60000);//  delay_ms(10000); delay_ms(10000);
           // delay_ms(10000); delay_ms(10000);   delay_ms(10000); delay_ms(10000);
            
           output_low(pin_d2);
           output_low(pin_d7);
           
              printf(lcd_putc,"\f");
              lcd_gotoxy(1,1);
              printf(lcd_putc,"MOBILE CHARGING ");
              lcd_gotoxy(3,2);
              printf(lcd_putc," STOPPED. ");
              delay_ms(2000);
               output_high(pin_d3);  //RED LED ON
               flag=0;
          
           }
       
      else
          {
          
           output_high(pin_d3);  //RED LED ON
           output_low(pin_d2);  //GREEN LED OFF
           output_low(pin_d7); //RELAY OFF
            
           
              printf(lcd_putc,"\f");
              lcd_gotoxy(2,1);
              printf(lcd_putc,"INSERT COIN ");
              lcd_gotoxy(3,2);
              printf(lcd_putc,"PLEASE........");
              
           }
    
            
           
    } //while loop
}  //main loop


