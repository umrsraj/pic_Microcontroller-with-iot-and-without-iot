/********************************************************************************
TITLE:HAND GESTURE CONTROLLED LAMP DIMMER 
PIC16F73,
A0,A1= MEMS SENSOR,
BO TO B4 = RF RECEIVER,
C4,C5,C6,C7 =  LED'S,
PWM PIN=C2,
**********************************************************************************/
#include <16F73.h>           //Microcontroller Used
#fuses HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)         // operating Clock freequency
#include "flex_lcd.c"
unsigned long duty = 0;

void main()
{
  unsigned x=0,y=0;  

//HEALTH CHECK UP STARTS.....
    output_high(PIN_C4);
    output_high(PIN_C5);    
    output_high(PIN_C6);
    output_high(PIN_C7);
    delay_ms(500);   
    output_low(PIN_C4);
    output_low(PIN_C5);    
    output_low(PIN_C6);
    output_low(PIN_C7);
    delay_ms(500);
    
    output_high(PIN_C4);
    output_high(PIN_C5);    
    output_high(PIN_C6);
    output_high(PIN_C7);
    delay_ms(500);   
    output_low(PIN_C4);
    output_low(PIN_C5);    
    output_low(PIN_C6);
    output_low(PIN_C7);
    delay_ms(500);
    
//PWM CHANNEL PROGRAMMING
duty = 0;
   setup_timer_2(T2_DIV_BY_16, 255, 1);
   
   setup_ccp1(CCP_PWM);
   set_pwm1_duty(duty);
    set_pwm1_duty(0);
    set_pwm2_duty(0); 
     setup_adc(ADC_CLOCK_INTERNAL);                             // SETTING UP ADC
     setup_adc_ports(ALL_ANALOG);  
    lcd_init();
    
   printf(lcd_putc,"\f");
   lcd_gotoxy(0,1);
   printf(lcd_putc,"HAND GESTURE BSD ");
   lcd_gotoxy(4,2);
   printf(lcd_putc,"LAMP DIMMER  ");
   delay_ms(2000);
   
   printf(lcd_putc,"\f");
   lcd_gotoxy(3,1);
   printf(lcd_putc,"USING TRIAC ");
   lcd_gotoxy(2,2);
   printf(lcd_putc,"*******************");
   delay_ms(2000);   
   
            printf(lcd_putc,"\f");
            lcd_gotoxy(3,1);
            printf(lcd_putc,"GESTUER LAMP");
            delay_ms(2000);  
   
   while(1)
   {      
      set_adc_channel(0);                           
      //delay_ms(1);
      x=read_adc(); 
     // delay_ms(1);
      
    set_adc_channel(1);                           
     // delay_ms(1);
      y=read_adc();
      //delay_ms(1);

         if(x>90)        // Intensity 100%
         { 
            output_high(PIN_C2);
            output_high(PIN_C4);
            set_pwm1_duty(1000);     
          // output_high(PIN_C2); //for motor
           //output_high(PIN_C1); //for motor
             delay_ms(100);   
           //output_low(PIN_C4);
          //set_pwm1_duty(0);     
            output_low(PIN_C4);
            // set_pwm1_duty(0);  
           lcd_gotoxy(0,2);
           printf(lcd_putc,"LIGHT INT= 100 PER");
                
         }
         
       else if((x<70))  // Intensity 70%
         {
           output_high(PIN_C2);  //LED ON 
           output_high(PIN_C5);
           set_pwm1_duty(60);     
          // output_high(PIN_C2); //for motor
           //output_high(PIN_C1); //for motor
          // delay_ms(1);  
           delay_us(300);
           output_low(PIN_C2);  //LED ON
           output_low(PIN_C5);
             set_pwm1_duty(0);
             lcd_gotoxy(0,2);
           printf(lcd_putc,"LIGHT INT= 70 PER");
               
        }
         
      else if(y>90)    // Intensity 30%
         {
          output_high(PIN_C2);  //LED ON 
          output_high(PIN_C6);
          set_pwm1_duty(30);     
          // output_high(PIN_C2); //for motor
           //output_high(PIN_C1); //for motor
          // delay_ms(1);   
          delay_us(250);
           output_low(PIN_C2);  //LED ON
           output_low(PIN_C6);
           set_pwm1_duty(0);  
         lcd_gotoxy(0,2);
         printf(lcd_putc,"LIGHT INT= 30 PER");
        // set_pwm1_duty(300); 
         // delay_us(1);
        }
     else if((y<70))   // Intensity 0%
         {                     
           output_high(PIN_C2);  //LED ON  
           output_high(PIN_C7);
           set_pwm1_duty(0);     
          // output_high(PIN_C2); //for motor
           //output_high(PIN_C1); //for motor
           delay_ms(1);   
           output_low(PIN_C2);  //LED ON
           output_low(PIN_C7);
          lcd_gotoxy(0,2);
          printf(lcd_putc,"LIGHT INT= 0 PER");
                          
         }
     else
      {
          // output_low(PIN_C2);  set_pwm1_duty(0);     
           output_low(PIN_C4);  //LED OFF  
           output_low(PIN_C5);  //LED OFF  
           output_low(PIN_C6);  //LED OFF  
           output_low(PIN_C7);  //LED OFF  
        // delay_ms(700); 
      }
                    
      
   } //WHILE CLOSE
} //MAIN CLOSE  

