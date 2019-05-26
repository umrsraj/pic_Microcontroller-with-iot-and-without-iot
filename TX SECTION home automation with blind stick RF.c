/*****************************************************************************
TITLE:TX SECTION home automation with blind stick RF   (TX SECTION )
PIC16f73
RF TX = B0 TO B4,
c4=GREEN LED,
c5= RED LED,
c3=BUZZER,
A0= IR,
A1 = SWITCH,
****************************************************************************/
#include <16F72.h>
#fuses  HS,NOWDT,PROTECT,brownout,put
#use delay  (clock=20M)
//#include <flexd7_lcd.c>

void buzzer()
{
output_high(pin_c3); //buzzer on
delay_ms(300);
output_low(pin_c3); //buzzer off
delay_ms(100);

}

/////////////////////////////////////////////////////////////////////////////////

//MAIN PROGRAMMING-------------------------------------------------------------
void main()
{
   float temp1,temp2,GAS,HUM;
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG ); 
 //  lcd_init();
  
   //HEALTH CHECK UP..........................................
   output_high(PIN_c3);  //BUZZER ON
   output_high(PIN_c4);  //GREEN LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(1000);
   output_low(PIN_c3);   //BUZZER OFF
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(1000);
     output_high(PIN_c3);  //BUZZER ON
   output_high(PIN_c4);  //GREEN LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(1000);
   output_low(PIN_c3);   //BUZZER OFF
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(1000);
   
   //ADC INITIALIZING 
   output_high (PIN_C4);
   output_low (PIN_C5);
/*DISPLAY INITIAL MESSAGE
          lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(1,1);
         printf(lcd_putc,"WIRELESS FAN SPEED");
         lcd_gotoxy(3,2);
         printf(lcd_putc,"  CNTRL S/M");         
         delay_ms(1500); 
         lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"SYSTEM USING WRL ");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"SENSOR NETWORK ");         
                delay_ms(1200);
*/
       //RF initialization
      output_high(pin_B0);
      delay_ms(200);
      
             
          //output_high(PIN_b2);    output_high(PIN_b3);    output_high(PIN_b4);
//CONTINEOUS LOOP...........................................
  while(1)
  {
 set_adc_channel(0);       //TEMPERATURE ............................                      
      delay_ms(1);
      temp2=read_adc(); 
      delay_ms(1);
     
    
     
//*****************************************************************
  
      if(temp2>155)
      {
      //output_high(pin_C5); //RED LED ON
      output_high(pin_C4); //GREEN LED OFF
      
      
         output_low(pin_B0);     //rf
          delay_ms(10);
         output_low(pin_B1);   //correct
         output_high(pin_B2);
         output_high(pin_B3);
         output_high(pin_B4);
             delay_ms(500);
       
       output_high(pin_c3);
      
      output_high(pin_B0);
      }      

       
      
      else 
      {
      output_low(pin_c3);
      output_low(pin_C4); //RED LED ON
      output_high(pin_C5); //GREEN LED OFF
      
         
      output_low(pin_B0); 
      output_high(pin_B1); 
      }
      
      
 
 }// WHILE......................................................................
  

}//MAIN

