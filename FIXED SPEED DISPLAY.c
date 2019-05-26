#include <16F877A.h>           //Microcontroller Used   
#fuses      HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include "dc_motor.c" 
#include "flex_lcd.c"
int16 duty_cycle=512;
unsigned int16 value=0;



void main()
{
   unsigned int16 value=0;
 
  
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
   lcd_init();   
   printf(lcd_putc,"\f");
   lcd_gotoxy(0,1);
   printf(lcd_putc,"DC MOTOR SPEED CTRL  ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"& MONITORING SYSTEM");
   delay_ms(500);
 
setup_timer_2(T2_DIV_BY_16,255,1);   // Set PWM frequency
setup_ccp1(CCP_PWM);          // Configure CCP1 to PWM mode
set_pwm1_duty(512L);          // default duty cycle = 50% (Half Speed)
//set_pwm1_duty(512L);
 /*********************************************************************************************************   
setup_ccp1(ccp_pwm);  //this turns the pwm on
setup_timer_2(t2_div_by_'1,255,1);     // see above for help on this(timer(1/f)*prscalar(16)*255(max period)*post scale)//setup_timer_2(mode, period,postscale)//T2_DIV_BY_16 is the prescale of the clock
//set_timer2(0); //start the counter at zero
*************************************************************************************************************/
   
       printf(lcd_putc,"\f");
        lcd_gotoxy(3,1);
      printf(lcd_putc,"MOTOR : OF");
       lcd_gotoxy(0,2);
      printf(lcd_putc,"SPEED ="); 
       lcd_gotoxy(8,2);
      printf(lcd_putc,"%LU RPM",value); 
    
   while(1)
   {      

    //1ST CONDITION    (START)
         if(!(input(pin_D7)))
         {
           value=60;
           
            // dyty=800;
           lcd_gotoxy(3,1);
      printf(lcd_putc,"MOTOR : ON");
      lcd_gotoxy(8,2);
      printf(lcd_putc,"%LU RPM",value);      
             output_high(pin_D2);                 //LED 2 ON
           M1_ON(1,0);                          //Left
           M2_ON(1,0);
           delay_ms(10);
           output_low(pin_D2);
              
        }
         
     
      
      
     //2ND CONDITION    (STOP)
             if(!(input(pin_D6)))
         { value=0;
         //LED 2 ON
            lcd_gotoxy(3,1);
      printf(lcd_putc,"MOTOR : OF");
      lcd_gotoxy(8,2);
      printf(lcd_putc,"%LU RPM",value);
          M1_ON(0,0);                          //Left
            M2_ON(0,0);
           delay_ms(10);
           output_low(PIN_D2);
      
        } 
        
                  
      
     //1ST SPEED CONTROL  30 PERCENT--------------------------------------------------------------
        if(!(input(pin_A0)))
      {
      value=30;  value=29;
       //   duty_cycle+=84;   // increase the duty cycle by some percentage (+6.25%)
          set_pwm1_duty(60); // set the duty cycle
          output_high(pin_C4);
          delay_ms(500);
          output_low(pin_C4);
          lcd_gotoxy(3,1);
      printf(lcd_putc,"MOTOR SPEED");
       lcd_gotoxy(8,2);
      printf(lcd_putc,"%LU RPM",value);
                         
        }
   
        
           if(!(input(pin_A1)))
      {
      value=60;value=67;
       //   duty_cycle+=84;   // increase the duty cycle by some percentage (+6.25%)
          set_pwm1_duty(100); // set the duty cycle
          output_high(pin_C4);
          delay_ms(500);
          output_low(pin_C4);
          lcd_gotoxy(3,1);
     printf(lcd_putc,"MOTOR SPEED");
       lcd_gotoxy(8,2);
      printf(lcd_putc,"%LU RPM",value);
                         
        }
        
           if(!(input(pin_A2)))
      {
      value=107;value=119;
       //   duty_cycle+=84;   // increase the duty cycle by some percentage (+6.25%)
          set_pwm1_duty(180); // set the duty cycle
          output_high(pin_C4);
          delay_ms(500);
          output_low(pin_C4);
          lcd_gotoxy(3,1);
     printf(lcd_putc,"MOTOR SPEED");
       lcd_gotoxy(8,2);
      printf(lcd_putc,"%LU RPM",value);
                         
        }
        
           if(!(input(pin_A3)))
      {
      value=150;
       //   duty_cycle+=84;   // increase the duty cycle by some percentage (+6.25%)
          set_pwm1_duty(255); // set the duty cycle
          output_high(pin_C4);
          delay_ms(500);
          output_low(pin_C4);
          lcd_gotoxy(3,1);
     printf(lcd_putc,"MOTOR SPEED");
       lcd_gotoxy(8,2);
      printf(lcd_putc,"%LU RPM",value);
                         
        }
   
   
   if(!(input(pin_b0)))
      {
          output_high(pin_d2);
          delay_ms(500);
          output_low(pin_d2);
                                   
        }
   
   
   } //WHILE LOOP
}  //MAIN LOOP
                        //LED 2 ON
