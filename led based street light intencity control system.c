/*******************************************************************************************************************
   Project Title:SOLAR POWERED STREET LIGHT WITH OBSTACLE SENSOR
   
   MC-PIC 16F73, 
   voltage sensor---ADC0  (A0),
   LDR= A1,
   C7= OBSTARCLE SENSOR(FOR VEHCLE PRESENCE)
   LCD--Bport (B2 TO B7),
   PWM2 pin for mosfet board C2 FOR (LIGHT INTENSITY CONTROL),
   BUZZER = B0,
   C4= GREEN LED,
   C5 = RED LED.

*********************************************************************************************************************/
#include <16F73.h>      //mc headerfile
#include <string.h>
#fuses  HS,NOWDT,PROTECT,brownout,put
#use delay  (clock=20M)
//#include <flex_lcd.c>

/*
float read_battery_voltage()
{   
   float value1;
   float value2;
   float value3;
   unsigned long final;
   float vol_final;
   float vol;
   //float temp = 0;
   set_adc_channel(0);
   delay_ms(10);
   value1 = Read_ADC();
   delay_ms(100);
   value2 = Read_ADC();
   delay_ms(100);
   value3 = Read_ADC();
   final = (value1 + value2 + value3)/3.0;
   vol = ((final*5.0)/255.0) * 6.0; //It works for 20 volts pannel (dont know why) (Trial and Error method)   
   return vol;   
}

void beep()
{
output_high(pin_b0);
delay_ms(1000);
output_low(pin_b0);
delay_ms(1000);
}
*/

// unsigned int duty = 10;
 
unsigned long duty = 30; 
//main rogram starts .........................................................

void main()
{  
  // unsigned int duty = 10;
unsigned long vol_read;
  unsigned long ldr;
//   lcd_init();
 
   setup_port_a( ALL_ANALOG );
   setup_adc(ADC_CLOCK_INTERNAL);
   
    
    setup_timer_2(T2_DIV_BY_16, 127, 1);
   
    setup_ccp1(CCP_PWM);
    set_pwm1_duty(duty);
   
    setup_ccp2(CCP_PWM);
    set_pwm2_duty(duty);
   
    set_pwm1_duty(duty);
    set_pwm2_duty(duty);
    
   
  //  beep();
   output_high(PIN_C4); //mosfet off
   output_high(PIN_C5); //mosfet off
   delay_ms(1000);
   output_low(PIN_C4); //mosfet off
   output_low(PIN_C5); //mosfet off
   delay_ms(1000);
   output_high(PIN_C4); //mosfet off
   output_high(PIN_C5); //mosfet off
   delay_ms(1000);
   output_low(PIN_C4); //mosfet off
   output_low(PIN_C5); //mosfet off
   delay_ms(1000);
   /*
   
  lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(1,1);
   printf(lcd_putc,"IMPLEMENTATIOMN OF");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"SOLAR POWER SAVING ");
 //  delay_ms(1500);
   
     lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(3,1);
   printf(lcd_putc,"SYSTEM FOR ");
   lcd_gotoxy(2,2);
   printf(lcd_putc,"STREET LIGHTS &");
  // delay_ms(1500);
   
     lcd_putc('\f');      //Clear LCD Display
   lcd_gotoxy(1,1);
   printf(lcd_putc,"AUTOMATIC TRAFFIC ");
   lcd_gotoxy(2,2);
   printf(lcd_putc,"CONTROL SYSTEM");
  // delay_ms(1500);
   
   
     */   
    
       
   
   while(1)
   {
        // vol_read = read_battery_voltage(); //read battery voltage
        
      //LDR PERCENTAGE.................... 
        set_adc_channel(0);
         delay_ms(10);
         ldr = Read_ADC();   //read ldr adc value
         
       //if BATTERY IS HEALTHY CONDITION...................................................................................................... 
       /*
       if(vol_read>11)      //BATTE >11V
        {
        
             output_high(pin_c4);  //green led on
             output_low(pin_c5);  //red led off
        
        //vehicle detection 
        */
        if(ldr>150) //obstacle senosr activated and nght mode
         {
          output_high(pin_c4);
          set_pwm1_duty(255);  //full duty cycle
          set_pwm2_duty(255);  //full duty cycle
           output_high(pin_c1);
          output_high(pin_c2);
         
           output_high(pin_c4);
          
            
            output_low(pin_c5);
         delay_ms(300);
           
         /*
         lcd_putc('\f');         //Clear LCD 
         lcd_gotoxy(1,1);
         printf(lcd_putc,"VEHICLE PRESENCE");     
         lcd_gotoxy(1,1);
         printf(lcd_putc,"STREET LIGHT ON");     
       //  delay_ms(1500); 
            
            

         lcd_putc('\f');         //Clear LCD 
         lcd_gotoxy(1,1);
         printf(lcd_putc,"STREET LIGHTS");     
         lcd_gotoxy(1,1);
         printf(lcd_putc,"INTESITY :100 PER");     
        // delay_ms(1500);
*/                
         }
          //high battery alert
         
                
         
       
         
         else {
         
         set_pwm1_duty(10);  //30 % duty cycle
         
        set_pwm2_duty(10);  //30 % duty cycle
          output_high(pin_c1);
          output_high(pin_c2);
        
        
         output_high(pin_c5);
          output_low(pin_c4);
        delay_ms(300);
         
       
         
       /*  
         
         //low battery voltage alert
          if(vol_read <7)
         {
            
            output_high(pin_c5); //red led on
            output_low(pin_c4); //green led off
            beep();  //buzzer on
            
        //  set_pwm1_duty(0);  //30 % duty cycle
         // set_pwm2_duty(0);  //30 % duty cycle
         
         lcd_putc('\f');         //Clear LCD 
         lcd_gotoxy(1,1);
         printf(lcd_putc,"LOW BATTERY ALERT****");     
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Voltage : %Lu V",vol_read);     
        delay_ms(1500); 
       
         } //battery low
         
        
         }
            delay_ms(700); 
        lcd_putc('\f');         //Clear LCD 
         lcd_gotoxy(1,1);
        // printf(lcd_putc,"STREET LIGHT SYSTEM");     
       printf(lcd_putc,"LDR Per : %Lu V",ldr);     
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Voltage : %Lu V",vol_read);     
        delay_ms(1500); 
         */
   }
         
   }  //while
   
}
