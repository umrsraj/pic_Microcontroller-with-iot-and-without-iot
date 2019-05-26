/******************************************************************************************
TITLE:AUTOMATIC SOLAR E UNIFROM WITH TEMPERATURE SENOR
PIC16F877A,

TEMP SENSOR= A0,
AC BATTERY INPUT REF= A1,

LCD= B PORT,
D2= GREEN LED,
D3= RED LED.
D0= BUZZER,
D7 =RELAY

*******************************************************************************************/
#include <16F73.h>
#fuses HS,NOWDT,PROTECT,brownout,put
//#device ADC = 8  //10 bit adc
#use delay(clock=20M)
#include <flex_lcd.c>


void beep()
{
output_high(pin_C3);
   delay_ms(500);
output_low(pin_C3);
 delay_ms(500);
}






void main() 
{

//unsigned int temp;
   float battery,pizeo;
   float temp1,temp2;
   lcd_init();
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );

output_high(pin_c4);
output_high(pin_c5);
   delay_ms(1000);
output_low(pin_c4);
output_low(pin_c5);
 delay_ms(1000);
output_high(pin_c4);
output_high(pin_c5);
   delay_ms(1000);
output_low(pin_c4);
output_low(pin_c5);
 delay_ms(1000);
 
 beep();
           output_low(pin_C7);  //RELAY ON
     
  //display initial messsage ....................................
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"HEATING & COOLING  ");
              lcd_gotoxy(4,2);
              printf(lcd_putc,"SUITE FOR ");
              delay_ms(2000);
              
                  printf(lcd_putc,"\f");
              lcd_gotoxy(4,1);
              printf(lcd_putc,"SOLDIERS ");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"-----------------");
              delay_ms(2000);
           
    while(TRUE)
    {
        
        
       set_adc_channel(0);       //TEMPERATURE ............................                      
      delay_ms(1);
      temp2=read_adc(); 
      delay_ms(1);
      temp1 = (temp2 * 100)/256;
      temp1 = temp1 * 5;
      
   //   set_adc_channel(2);
     // delay_ms(50);// delay built-in function call
   //   battery = Read_ADC();                   // A/D read functions- built-in         
  //    battery=battery*123/1023;
         //  battery=battery*5.0*10/1023; 
      /*
      lcd_putc("\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"voltage:%f ",battery);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"pizeo:%f volts ",pizeo);
      delay_ms(5000);
      */
      
      
      
      if((temp1<40)&&(temp1>20))
      {
              printf(lcd_putc,"\f");
              lcd_gotoxy(3,1);
              printf(lcd_putc,"COOLER : OFF  ");
              lcd_gotoxy(3,2);
              printf(lcd_putc,"HEATER : OFF  ");
             
             output_low(pin_c7); //cooler on
             output_low(pin_c6); //heater off
             delay_ms(2000);
       
      }
      
      
      
      
      // IF TEMPERATURE 
      if(temp1>40)
      {
             output_high(pin_c7); //cooler on
             output_low(pin_c6); //heater off
              printf(lcd_putc,"\f");
              lcd_gotoxy(3,1);
              printf(lcd_putc,"COOLER : ON  ");
              lcd_gotoxy(3,2);
              printf(lcd_putc,"HEATER : OFF  ");
              delay_ms(2000);
      
      }
      
      if(temp1<20)
      {      output_high(pin_c6); //heater on
             output_low(pin_c7); //cooler off  
               printf(lcd_putc,"\f");
              lcd_gotoxy(3,1);
              printf(lcd_putc,"COOLER : OFF  ");
              lcd_gotoxy(3,2);
              printf(lcd_putc,"HEATER : ON  ");
               delay_ms(2000);
               
      
      }
          
   
           output_high(pin_C4);  //RELAY ON
           output_low(pin_C5);  //RELAY ON
          output_low(pin_C3);  //RELAY ON
             
      printf(lcd_putc,"\f");
      lcd_gotoxy(3,1);
      printf(lcd_putc,"T=%2.0g%cC",temp1,0xDF);
       lcd_gotoxy(1,2);
       printf(lcd_putc,"AUTOMATIC SUITE");
       delay_ms(700);
      
      
    } //while loop
}  //main loop




