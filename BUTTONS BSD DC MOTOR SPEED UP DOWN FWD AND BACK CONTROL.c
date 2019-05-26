

/*********************************************************************************************************************************************

   Project Title: PUSH BUTTON BASED DC MOTOR SPEED AND DIRECTION CONTROL USING L293D

   MC-PIC16F877A,D2.D3,C4,C5--LED, 
   A0,A1,A2,A4= PUSH BUTTONS,
   L293D MOTOR = C0 TO GND

***********************************************************************************************************************************************/

#include <16f877a.h>
#fuses HS,PUT, PROTECT, NOWDT
#use delay(clock=20M)
#include "flex_lcd.c"
#include "dc motor.c"


int16 duty_cycle=512;

void main()
{
   int data;

  output_high(pin_d2);
 output_high(pin_d3);
 output_high(pin_c4);
 output_high(pin_c5);
 delay_ms(500);
 output_low(pin_d2);
 output_low(pin_d3);
 output_low(pin_c4);
 output_low(pin_c5);
 delay_ms(500);
 output_high(pin_d2);
 output_high(pin_d3);
 output_high(pin_c4);
 output_high(pin_c5);
 delay_ms(500);
 output_low(pin_d2);
 output_low(pin_d3);
 output_low(pin_c4);
 output_low(pin_c5);
 delay_ms(500);
 
 
 Lcd_Init();
setup_timer_2(T2_DIV_BY_16,255,1);   // Set PWM frequency
setup_ccp1(CCP_PWM);          // Configure CCP1 to PWM mode
set_pwm1_duty(512L);          // default duty cycle = 50% (Half Speed)
//set_pwm1_duty(512L);
 /*********************************************************************************************************   
setup_ccp1(ccp_pwm);  //this turns the pwm on
setup_timer_2(t2_div_by_1,255,1);     // see above for help on this(timer(1/f)*prscalar(16)*255(max period)*post scale)//setup_timer_2(mode, period,postscale)//T2_DIV_BY_16 is the prescale of the clock
//set_timer2(0); //start the counter at zero
*************************************************************************************************************/

   while(1)
   {

 
 // MOTOR = OFF
if(!(input(pin_E1)))            //IF A0 SWITCH PRESSED ==0
        {
       delay_ms(50);
       output_low(pin_C3);             //Make positive of motor 0
       output_low(pin_D0);             //Make negative of motor 1
               
          output_low(pin_D2);
           printf(lcd_putc,"\f");
          lcd_gotoxy(1,1);
          printf(lcd_putc,"MOTOR = OFF ");
          delay_ms(500);
  }
        
          
               //MOTOR ON 
 else if(!(input(pin_E0)))            //IF A0 SWITCH PRESSED ==0
        {
       delay_ms(50);
       output_low(pin_C3);             //Make positive of motor 0
       output_high(pin_D0);             //Make negative of motor 1
       
          output_high(pin_D2);
          delay_ms(500);
        //  output_low(pin_D2);
         
          printf(lcd_putc,"\f");
          lcd_gotoxy(1,1);
          printf(lcd_putc,"MOTOR = ON  ");
          delay_ms(500);
        }
              
              
     else  if(!(input(pin_A0)))            //IF A0 SWITCH PRESSED ==0
        {

         if(duty_cycle<=1015)
         {
          duty_cycle+=84;   // increase the duty cycle by some percentage (+6.25%)
          set_pwm1_duty(duty_cycle); // set the duty cycle
          output_high(pin_d2);
          delay_ms(500);
          output_low(pin_d2);
          printf(lcd_putc,"\f");
          lcd_gotoxy(0,1);
          printf(lcd_putc,"MOTOR = SPEED UP   ");
          delay_ms(500);
          }
        }
           
           
              //speed down
else if(!(input(pin_A1)))            //IF A1 SWITCH PRESSED ==0
        {
          if(duty_cycle>10)
         {
         duty_cycle-=84;   // decrease the duty cycle
         set_pwm1_duty(duty_cycle); // set the duty cycle
         output_high(pin_d3);
          delay_ms(500);
          output_low(pin_d3);
          printf(lcd_putc,"\f");
            lcd_gotoxy(0,1);
          printf(lcd_putc,"MOTOR = SPEED DN   ");
          delay_ms(500);
         }
        }                
     
           
          //left speed----     
 else if(!(input(pin_A2)))            //IF A0 SWITCH PRESSED ==0
        {
        if(duty_cycle>10)
         {         delay_ms(50);
          output_high(pin_C3);             //Make positive of motor 1
          output_low(pin_D0);             //Make negative of motor 0
          output_high(pin_c4);
          delay_ms(500);
          output_low(pin_c4);
          printf(lcd_putc,"\f");
          lcd_gotoxy(0,1);
          printf(lcd_putc,"MOTOR = LEFT  ");
          delay_ms(500);
         }
        }    
               
               //RIGHT SPEED ------
 else if(!(input(pin_A3)))            //IF A0 SWITCH PRESSED ==0
        {
       delay_ms(50);
       output_low(pin_C3);             //Make positive of motor 0
       output_high(pin_D0);             //Make negative of motor 1
       
          output_high(pin_c5);
          delay_ms(500);
          output_low(pin_c5);
         
          printf(lcd_putc,"\f");
            lcd_gotoxy(0,1);
          printf(lcd_putc,"MOTOR = RIGHT   ");
          delay_ms(500);
        }
      
      


      }  //while
   
} //main loop





