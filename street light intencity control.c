/*********************************************************************************************************************************************
ir based street light control system
   MC-PIC16F877A, 
***********************************************************************************************************************************************/
#include <16f877A.h>
#fuses HS,PUT,NOWDT,NOPROTECT
#use delay(clock=20000000)
//#define ADC=8

void main(void)
{
//int x_coord;

//setup_adc(ADC_CLOCK_INTERNAL);
//setup_adc_ports(RA0_ANALOG);
//setup_adc_ports(ALL_ANALOG);


 
   
    setup_ccp1(CCP_PWM);
   // set_pwm1_duty(0);
   
    setup_ccp2(CCP_PWM);
    //set_pwm2_duty(0);
   
    //setup_timer_2(T2_DIV_BY_16, 127, 1)
     setup_timer_2(T2_DIV_BY_16, 255, 1);
   
    set_pwm1_duty(0);
    set_pwm2_duty(0);
    

  
         
          output_high(pin_D2);                 //LED 2 ON 
          output_high(pin_D3);                 //LED 2 ON
         output_high(pin_c4);                 //LED 2 ON
          output_high(pin_c5);                 //LED 2 ON
          delay_ms(500);
           output_low(pin_D2);                 //LED 2 ON 
          output_low(pin_D3);                 //LED 2 ON
         output_low(pin_c4);                 //LED 2 ON
          output_low(pin_c5);                 //LED 2 ON
     delay_ms(500);
    
    
          output_high(pin_D2);                 //LED 2 ON 
          output_high(pin_D3);                 //LED 2 ON
         output_high(pin_c4);                 //LED 2 ON
          output_high(pin_c5);                 //LED 2 ON
          delay_ms(500);
           output_low(pin_D2);                 //LED 2 ON 
          output_low(pin_D3);                 //LED 2 ON
         output_low(pin_c4);                 //LED 2 ON
          output_low(pin_c5);                 //LED 2 ON
     delay_ms(500);
    
   while(1)
   {      
 
 //*******+++++++++++++++++++++++
               set_pwm1_duty(60);
               delay_ms(60);
               set_pwm2_duty(100);
               delay_ms(60);
               
               output_high(pin_d2);
               output_low(pin_d3);
             
 
 
 if (input(pin_A0))
 {
 ///////////////////////////////////
  set_pwm1_duty(255);
delay_ms(60);
               set_pwm2_duty(255);
             delay_ms(60);
             
               output_high(pin_d3);
               output_low(pin_d2);
 ///////////////////////////////
  
 
 
 }
   }
}
 
 
 //+++++++++++++++++++++++++++++++++++
 
 /*
  //1ST BUTTON
if(!(input(pin_a0)))  
{  

             set_pwm1_duty(0);
             set_pwm2_duty(0);
             
             output_low(pin_C1); output_low(pin_C2); 
             output_high(pin_D2); //LED 2 ON
           
              lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc,"    OPTION -1  ");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"  SPEED =0 RPM");         
        
            delay_ms(1000);
            // output_low(pin_D2); 
            output_low(pin_D3);  output_low(pin_c4);  output_low(pin_c5);                 //LED 2 ON
        }
         
         
             //2ND BUTTON
 // if((x_coord>50)&&(x_coord<75))
 // if(!input(pin_a1))  
 else if(!(input(pin_a1)))  
{
while((input(pin_a2)))
{
             set_pwm1_duty(250);
             set_pwm2_duty(250);
             output_high(pin_D3);  //LED 2 ON
             output_high(pin_C1); output_high(pin_C2); 
              lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc,"   OPTION -2  ");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"  SPEED =400 RPM"); 
         delay_ms(100);
             output_low(pin_C1);  output_low(pin_C2);                 //LED 2 ON
               set_pwm1_duty(0);
             set_pwm2_duty(0);
      
            output_low(pin_D2);  output_low(pin_c4);  output_low(pin_c5); // output_low(pin_D3);                 //LED 2 ON
             
            delay_ms(300);
  
  
  
  
  
if(!(input(pin_a0)))  
{  

     set_pwm1_duty(0);
             set_pwm2_duty(0);
             
             output_low(pin_C1); output_low(pin_C2); 
             output_high(pin_D2); //LED 2 ON
           
              lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc,"    OPTION -1  ");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"  SPEED =0 RPM");         
        
            delay_ms(1000);
            // output_low(pin_D2); 
            output_low(pin_D3);  output_low(pin_c4);  output_low(pin_c5);                 //LED 2 ON
             break;
        }
  
       
}//while
        }
        
        
        
            //1ST BUTTON
 //   if((x_coord>75)&&(x_coord<105))
 else if(!(input(pin_a2))) 
 {
 // if(!(input(pin_a2))) 
 while((input(pin_a3)))
 {

  set_pwm1_duty(250);
             set_pwm2_duty(250);
            // output_high(pin_D3);  //LED 2 ON
             output_high(pin_C1); output_high(pin_C2); 
            
          lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc,"    OPTION -3  ");
         lcd_gotoxy(0,2);
         printf(lcd_putc," SPEED =700 RPM"); 
             output_high(pin_C4); 
             delay_ms(200);
             output_low(pin_C1);  output_low(pin_C2);                 //LED 2 ON
             set_pwm1_duty(0); set_pwm2_duty(0);
             //output_low(pin_D3);  //LED 2 ON  
              output_low(pin_D2);  output_low(pin_d3);  output_low(pin_c5); 
               delay_ms(200);
 
 
 
if(!(input(pin_a0)))  
{  

     set_pwm1_duty(0);
             set_pwm2_duty(0);
             
             output_low(pin_C1); output_low(pin_C2); 
             output_high(pin_D2); //LED 2 ON
           
              lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc,"    OPTION -1  ");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"  SPEED =0 RPM");         
        
            delay_ms(1000);
            // output_low(pin_D2); 
            output_low(pin_D3);  output_low(pin_c4);  output_low(pin_c5);                 //LED 2 ON
            break;
        }
  
 
 
 }//while
              
        }
        
        
        
            //1ST BUTTON
  //if((x_coord>105)&&(x_coord<240))
  //if(!(input(pin_a3)))
  else if(!(input(pin_a3)))  
 {              
 lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc,"    OPTION -4  ");
         lcd_gotoxy(0,2);
         printf(lcd_putc," SPEED =1350 RPM"); 
             set_pwm1_duty(233);
             set_pwm2_duty(233);
             output_high(pin_c5);                 //LED 2 ON
          
           delay_ms(1000);
             // output_low(pin_C5);                 //LED 2 ON
              output_low(pin_d2);  output_low(pin_d3);  output_low(pin_c4); 
          
        }
        
        
        
         
   } //WHILE LOOP
}  //MAIN LOOP
         
*/
