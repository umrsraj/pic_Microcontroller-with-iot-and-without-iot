/*******************************************************************************************************************
   Project Title:SOLAR TRACKING SYSTEM WTH LDR SENSOR(WITHOUT LIMIT SWITCHES)
   
   MC-PIC 16F873
   LCD--Bport,
   //BUZZER =B0,
   c4= GREEN LED,
   c5 = RED LED,
   //voltage sensor---A0  (ADC 0) FOR MEASURE SOLAR VOLTAGE  ,
   LDR 1= A0,
   LDR  2= A1,
*********************************************************************************************************************/
#include <16F73.h>           //Microcontroller Used    pic16f877a 40pin size
#fuses HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
//#include "dc motor.c"    //dc motor header file
#include "flex_lcd.c"


float read_battery_wvoltage()
{   
   float value1;
   float value2;
   float value3;
   unsigned long final;
   float vol_final;
   float vol;
   //float temp = 0;
   set_adc_channel(2);
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

float read_battery_svoltage()
{   
   float value11;
   float value21;
   float value31;
   unsigned long final1;
   float vol_final1;
   float vol1;
   //float temp = 0;
   set_adc_channel(3);
   delay_ms(10);
   value11 = Read_ADC();
   delay_ms(100);
   value21 = Read_ADC();
   delay_ms(100);
   value31 = Read_ADC();
   final1 = (value11 + value21 + value31)/3.0;
   vol1 = ((final1*5.0)/255.0) * 6.0; //It works for 20 volts pannel (dont know why) (Trial and Error method)   
   return vol1;   
}



void beep()
{
output_high(pin_b0);
delay_ms(1000);
output_low(pin_b0);
delay_ms(1000);
}


void main()
{
int direction;
unsigned int LDR1,LDR2;
float vol_read;
float vol1_read;

unsigned windv,solarv;
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG ); 
   
   lcd_init();
    lcd_putc("\f");
  lcd_gotoxy(0,1);
   printf(lcd_putc,"AUTOMATIC SOLAR  ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"TRACKING SYSTEM");
   delay_ms(2000); 
   
 
   output_high(pin_c4);   
   output_high(pin_c5);
  // beep();
   delay_ms(500);    
   output_low(pin_c4);   
   output_low(pin_c5);
   delay_ms(500); 
    output_high(pin_c4);   
   output_high(pin_c5);
   //beep();
   delay_ms(500);
   output_low(pin_c4);   
   output_low(pin_c5);
   delay_ms(500);
   
 lcd_putc('\f'); 
 
while(1)
{
    vol_read = read_battery_wvoltage(); 
    vol1_read = read_battery_svoltage(); 
    
    //windv = vol_read;
   // solarv = vol1_read;
    
      set_adc_channel(0);
      delay_ms(50);
      LDR1 = Read_ADC();  
      
      set_adc_channel(1);
      delay_ms(50);
      LDR2 = Read_ADC();  
      
 
         lcd_putc('\f');         //Clear LCD 
         lcd_gotoxy(1,1);
      // printf(lcd_putc,"Voltage : %Lu V",vol_read); 
        printf(lcd_putc,"W= %2.2f,S= %2.2f",vol_read,vol1_read);
         lcd_gotoxy(0,2);
         printf(lcd_putc,"L1:%u,L2:%u ",LDR1,LDR2);
         delay_ms(500);
      
      

if(LDR1<=30)//a0
{
output_high(pin_c2);
output_low(pin_c3);
output_high(pin_c4);
output_low(pin_c5);
delay_ms(500);

output_low(pin_c2);
output_low(pin_c3);
delay_ms(5);

output_low(pin_c4);
}
if(LDR2<=30)//a1
{
output_low(pin_c2);
output_high(pin_c3);
output_high(pin_c5);
output_low(pin_c4);
delay_ms(500);

output_low(pin_c2);
output_low(pin_c3);
delay_ms(5);

output_low(pin_c4);
   
}


if((LDR2>=140)&&(LDR2>=140))
{
output_high(pin_c7);delay_ms(500);
}

if((LDR2<=140)&&(LDR2<=140))
{
output_low(pin_c7);delay_ms(500);
}

} //WHILE
} //MAIN

