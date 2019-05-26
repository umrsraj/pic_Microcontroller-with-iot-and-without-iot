/*****************************************************************************
TITLE: HIGH POWER LED BASED STREET LIGHT WITH VEHICLE PRESENCE AND DAY/NIGHT
Ao-- ir sensor
A1 -- LDR
C1,C2 -- PWM STREET LIGHTS
c4,C5 -- G,R LEDS

********************************************************************************/
#include <16F73.h>        //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
//#use rs232(baud=9600, xmit=PIN_A1, rcv=PIN_A0,stream=PC)  //
//#include "dc_motor.c"


/*
void buzzer()
{
output_high(pin_c3); //buzzer on
delay_ms(700);
output_low(pin_c3); //buzzer off
delay_ms(700);

}

*/
unsigned int ldr = 0;
unsigned int ir = 0;


//MAIN PROGRAMMING....................................
void main()
{
      
      //output_high(PIN_c3);  //BUZZER ON
   output_high(PIN_c4);  //GREEN LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(1000);
 //  output_low(PIN_c3);   //BUZZER OFF
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(1000);
 //   output_high(PIN_c3);  //BUZZER ON
   output_high(PIN_c4);  //GREEN LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(1000);
  // output_low(PIN_c3);   //BUZZER OFF
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(1000);
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );
   
        setup_ccp1(CCP_PWM);
   // set_pwm1_duty(0);
   
    setup_ccp2(CCP_PWM);
    //set_pwm2_duty(0);
   
    //setup_timer_2(T2_DIV_BY_16, 127, 1)
     setup_timer_2(T2_DIV_BY_16, 255, 1);
   
    set_pwm1_duty(0);
    set_pwm2_duty(0);
    

     
       
  
       
 //fprintf(PC,"**************************************************************\r\n");delay_ms(200);
// fprintf(PC,"DEVELOPEMENT OF GAS & FIRE LEAKAGE DETECTION \r\n");delay_ms(200);
  //fprintf(PC,"        WITH WIRELESS SENSOR NETWORK\r\n");delay_ms(200);
// fprintf(PC,"**************************************************************\r\n");
  //delay_ms(1000);
     
 
   while(1)
   {
   
    set_adc_channel(0);
      delay_ms(50);// delay built-in function call
      ir = Read_ADC();                   // A/D read functions- built-in         
             
        set_adc_channel(1);
      delay_ms(50);// delay built-in function call
      ldr = Read_ADC();                   // A/D read functions- built-in         
             
   if (ldr>100)
   {
   if(ir>100)
   {
   output_high(pin_c4);
   output_low(pin_c5);
   
   output_high(pin_c1);
   output_high(pin_c2);
   
    set_pwm1_duty(255);
    set_pwm2_duty(255);
   
   }
   else
   {
   output_high(pin_c5);
   output_low(pin_c4);
   
   output_high(pin_c1);
   output_high(pin_c2);
   
    set_pwm1_duty(5);
    set_pwm2_duty(5); 
   }
   
   }
   else
   {
    output_low(pin_c4);
    output_low(pin_c5);
     set_pwm1_duty(0);
    set_pwm2_duty(0); 
   }
      
} //while 
                              
} //main

