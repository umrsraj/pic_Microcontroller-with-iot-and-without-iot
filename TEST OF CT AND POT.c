/*****************************************************************************
TITLE:  DEV OF SOLAR POWER MONITORING SYSTEM

PIC16F877A
LCD=B2 TO B7
A0= TEMPERATURE SENSOR,
A1= LDR,
A2 = VOLTAGE,
A3= CURRENT,

D3= RED LED,
D2 = GREEN LED

********************************************************************************/
#include <16F877A.h>        //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include "flex_lcd.c"

unsigned long V;
unsigned int LDR;

float I,vol,c;

void beep()
{
output_high(pin_D1);delay_ms(300);output_low(pin_D1);delay_ms(300);
output_high(pin_D1);delay_ms(300);output_low(pin_D1);delay_ms(300);
output_high(pin_D1);delay_ms(300);output_low(pin_D1);delay_ms(300);
}
//VOLTAGE REDING-----------------

float read_battery_voltage()
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

//CURRENT READING-------------

float read_battery_current()
{   
   float cur1;
   float cur2;
   float cur3;
   unsigned long final1;
   float cur_final;
   float cur;
   //float temp = 0;
   set_adc_channel(3);
   delay_ms(10);
   cur1 = Read_ADC();
   delay_ms(100);
   cur2 = Read_ADC();
   delay_ms(100);
   cur3 = Read_ADC();
   final1 = (cur1 + cur2 + cur3)/3.0;
   cur = ((final1*5.0)/255.0) * 6.0; //It works for 20 volts pannel (dont know why) (Trial and Error method)   
   return cur;   
}



//MAIN PROGRAMMING....................................
void main()
{
//int temp;
   float temp1;
   unsigned int temp2;    //,V,I;
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG ); 
    
     lcd_init();
     
  
//DISPLAY INITIAL MESSAGE
          lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc," IDENTIFICATOIN ");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"POWER FAILURE IN");         
         delay_ms(2000); 
     
      lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc,"   INDUSTRIES   ");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"****************");         
         delay_ms(2000); 
     
     
      output_high(pin_D2);       // Health check        
      output_high(pin_D3);
       delay_ms(500);
      output_low(pin_D2);
      output_low(pin_D3);
      //delay_ms(500);
      beep();
      output_high(pin_D2);       // Health check        
      output_high(pin_D3);
       delay_ms(500);
      output_low(pin_D2);
      output_low(pin_D3);
      delay_ms(500);
 
      
   while(TRUE)
   {
 
      set_adc_channel(0);       //TEMPERATURE ............................                      
      delay_ms(1);
      temp2=read_adc(); 
      delay_ms(1);
      temp1 = (temp2 * 100)/256;
      temp1 = temp1 * 5;
    
    
      set_adc_channel(1);      //GAS LEAKAGE.................................                     
      delay_ms(1);
      LDR=read_adc(); 
        delay_ms(1);
        
      //  LDR = LDR/100;
       
  if (LDR>25)
  {
  output_low(pin_d7);
 output_low(pin_D2); //FAN ON
       output_high(pin_D3); //GREEN LED OFF
       
       lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc,"HIGH CURRENT ALERT");
         lcd_gotoxy(0,2);
          printf(lcd_putc,"V=%u V",temp2);
          lcd_gotoxy(10,2);
          printf(lcd_putc,"I=%u mA",LDR);
          beep();
          delay_ms(5000);        
  
  
  }
       
       
       
       
  else if (temp2 >240)
   {
   output_low(pin_d7);
      output_low(pin_D2); //FAN ON
       output_high(pin_D3); //GREEN LED OFF
       
       lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc," HIGH VOL ALERT ");
         lcd_gotoxy(0,2);
          printf(lcd_putc,"V=%u V",temp2);
          lcd_gotoxy(10,2);
          printf(lcd_putc,"I=%u mA",LDR);
           beep();
          delay_ms(500);
         
   }
   
  else if (temp2 <220)
   {
   output_low(pin_d7);
      output_low(pin_D2); //FAN ON
       output_high(pin_D3); //GREEN LED OFF
       
       lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc," LOW VOL ALERT  ");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"V=%u V",temp2);
          lcd_gotoxy(10,2);
          printf(lcd_putc,"I=%u mA",LDR);
          beep();
          delay_ms(500);        
   }
   else 
   {
      output_high(pin_d7);
      output_high(pin_D2); //FAN ON
       output_low(pin_D3); //GREEN LED OFF
       
       lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc,"SYSTEM IS NORMAL");
         lcd_gotoxy(0,2);
          printf(lcd_putc,"V=%u V",temp2);
          lcd_gotoxy(10,2);
          printf(lcd_putc,"I=%u mA",LDR);
          delay_ms(500);
   }
 
 
      } //WHILE
                              
      } //MAIN


