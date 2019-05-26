#include <16F877A.h>           //Microcontroller Used   
#fuses      HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include "dc_motor.c" 
#include "flex_lcd.c"
int16 duty_cycle=512;
unsigned int16 value=0;


#INT_EXT
void ext_isr(void)
{


 if(!input(pin_b0))
     {
    
     output_high(pin_d2);
        value+=1;
       //  lcd_gotoxy(8,2);
     // printf(lcd_putc,"%LU RPM",value);
     delay_ms(30);
      
    
    }while(!input(pin_b0));
 output_low(pin_d2);//delay_ms(50);
 
 
      lcd_gotoxy(8,2);
      printf(lcd_putc,"%LU RPM",value); 
      output_low(pin_d2);delay_ms(10);
  
   
 if(input(pin_b0))
 {

   if(value==1)
     {
      value=0; 
       lcd_gotoxy(8,2);
      printf(lcd_putc,"%LU RPM",value);
      delay_ms(50);
     }
     
     if(value>1)
     {
      value-=1;
       lcd_gotoxy(8,2);
      printf(lcd_putc,"%LU RPM",value);
      delay_ms(30);
     }
  
} //else    


} //interrupt


void main()
{
   unsigned int16 value=0;
 
  ext_int_edge(H_TO_L);       // Interrupt on falling edge of RB0/INT pin
  //ext_int_edge(L_TO_H);       // Interrupt on falling edge of RB0/INT pin
  clear_interrupt(INT_EXT);   // Clear RB0/INT external interrupt flag bit
  enable_interrupts(INT_EXT); // Enable RB0/INT external interrupt
  enable_interrupts(GLOBAL);  // Enable all unmasked interrupt
 
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
      printf(lcd_putc,"%LU",value); 
    
   while(1)
   {      


/*
if(input(pin_b0))
 {
output_high(pin_d3);
   if(value)
     {
      value=0; 
     //  lcd_gotoxy(8,2);
     // printf(lcd_putc,"%LU RPM",value);
     //delay_ms(50);
     }
     
     if(value>1)
     {
      value-=1;
      // lcd_gotoxy(8,2);
     // printf(lcd_putc,"%LU RPM",value);
    delay_ms(500);
     }

 delay_ms(500);
 
}//while(input(pin_b0)); //else    
 
  output_low(pin_d3);  
      lcd_gotoxy(8,2);
     printf(lcd_putc,"%LU RPM",value);
      delay_ms(100);   
    
    
  */   
 // speed();
  
    //1ST CONDITION    (START)
         if(!(input(pin_A0)))
         {
           // speed();
            // dyty=800;
           lcd_gotoxy(3,1);
      printf(lcd_putc,"MOTOR : ON");
            
             output_high(pin_D2);                 //LED 2 ON
           M1_ON(1,0);                          //Left
           M2_ON(1,0);
           delay_ms(10);
           output_high(pin_D2);
              
        }
         
  
         
     //2ND CONDITION    (STOP)
             if(!(input(pin_A1)))
         {  //speed();
         //LED 2 ON
            lcd_gotoxy(3,1);
      printf(lcd_putc,"MOTOR : OF");
          M1_ON(0,0);                          //Left
            M2_ON(0,0);
           delay_ms(10);
           output_low(PIN_D2);
      
        } 
        
                  
      
     //3RD CONITION SPEED UP++++++++
        if(!(input(pin_A2)))
        {
       if(duty_cycle<=1015)
          {
          //speed();
          duty_cycle+=84;   // increase the duty cycle by some percentage (+6.25%)
          set_pwm1_duty(duty_cycle); // set the duty cycle
          output_high(pin_C4);
          delay_ms(500);
          output_low(pin_C4);
          lcd_gotoxy(3,1);
      printf(lcd_putc,"MOTOR : ++");
          
        }
                    
        }
      
      //4TH CONDITION (SPEED DOWN)-----
         if(!(input(pin_A3)))   
         {
            if(duty_cycle>10)
         {
        // speed();
         duty_cycle-=84;   // decrease the duty cycle
         set_pwm1_duty(duty_cycle); // set the duty cycle
         output_high(pin_c5);
          delay_ms(500);
          output_low(pin_c5);
             lcd_gotoxy(3,1);
      printf(lcd_putc,"MOTOR : --");
          
         }

         }
   
   } //WHILE LOOP
}  //MAIN LOOP
                        //LED 2 ON
