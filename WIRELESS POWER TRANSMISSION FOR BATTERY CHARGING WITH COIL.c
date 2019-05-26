/********************************************************************************
TITLE:WIRELESSS POWER TRANSMISSION FOR MOBILE CHARGER USING INDUCTION MECHANISM
PIC16F73,
C4 =  LED,
PWM PIN=C2,



**********************************************************************************/

#include <16F73.h>           //Microcontroller Used
#fuses      HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
unsigned long duty = 30;

void main()
{

    

//HEALTH CHECK UP STARTS.....
    output_high(PIN_C4);
    delay_ms(500);   
    output_low(PIN_C4);
    delay_ms(500);
    
    output_high(PIN_C4);
    delay_ms(500);   
    output_low(PIN_C4);
    delay_ms(500);
    
    
//PWM CHANNEL PROGRAMMING
duty = 30;
   setup_timer_2(T2_DIV_BY_16, 255, 1);
   
   setup_ccp1(CCP_PWM);
   set_pwm1_duty(duty);
 
    
    
   
   while(1)
   {      

           output_high(PIN_C4);  //LED ON 
          // output_high(PIN_C2);  // 
           set_pwm1_duty(100);     
           delay_ms(5);   
           output_low(PIN_C4);  //LED OFF
          // output_low(PIN_C2);   
           // delay_ms(5); 
            //set_pwm1_duty(0);     
            // delay_ms(5); 
              
      
   } //WHILE CLOSE
} //MAIN CLOSE  
      
