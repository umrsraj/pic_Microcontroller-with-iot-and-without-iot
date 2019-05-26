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

unsigned long V,LDR;

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
   float temp1,temp2;    //,V,I;
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG ); 
    
     lcd_init();
     
  
//DISPLAY INITIAL MESSAGE
          lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(0,1);
         printf(lcd_putc,"  SOLAR POWER ");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"MONITORING SYSTEM");         
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
       
      V = read_battery_voltage(); //read battery voltage
      I = read_battery_current(); //read battery voltage
      I= (I*2);
      I= I/100;
           
          lcd_putc('\f');  //FORMATE LCD DISPLAY
          lcd_gotoxy(0,1);
          printf(lcd_putc,"T= %2.0g%cC",temp1,0xDF);
          lcd_gotoxy(10,1);
          printf(lcd_putc,"L= %lu",LDR); 
          lcd_gotoxy(0,2);
          printf(lcd_putc,"V= %luV",V);
          lcd_gotoxy(8,2);
          printf(lcd_putc,"I= %2.2fmA",I);
          delay_ms(1000); 
       
    
      
 //-----TEMP COMPARE ---------     
      if(temp2>65)
      {
       output_low(pin_D2); //FAN ON
       output_high(pin_D3); //GREEN LED OFF
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"**VOLTAGE HIGH**");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"PLEASE CHECK...");
    //  beep();
      delay_ms(1500);
       }   
      
       //2nd
      if(LDR>180)   //NIGHT
      {
       output_low(pin_D2); //FAN ON
       output_high(pin_D3); //GREEN LED OFF
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"**NIGHT MODE** ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"---DETECTED----");
      beep();
      delay_ms(1500);
      }
     /*
 //VOLTAGE DETECTED-------------  
   //SOLAR HIGH VOLTAGE ALERT----      
      if((V<3)&&(V>14))   
      {
        output_low(pin_D2); //FAN ON
       output_high(pin_D3); //GREEN LED OFF
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"SOL VOLTAGE ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"---ALERT----");
      beep();
      delay_ms(1500);  
       }
     
   
 //CURRENT DETECTED-------------  
         if((I<3)&&(I>12))   
      {
        output_low(pin_D2); //FAN ON
       output_high(pin_D3); //GREEN LED OFF
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"SOL CURRENT ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"---ALERT----");
      beep();
      delay_ms(1500);  
       }
    */
 //ELSE NORMAL CONDITION----------------------
 //if((temp1<45)&&(LDR<180)&&((V>3)&&(V<12))&&((I>3)&&(I<12))) 
 if((temp1<45)&&(LDR<180)) 
 {
        output_low(pin_D3); //FAN ON
       output_high(pin_D2); //GREEN LED OFF
  
          lcd_putc('\f');  //FORMATE LCD DISPLAY
          lcd_gotoxy(0,1);
          printf(lcd_putc,"T= %2.0g%cC",temp1,0xDF);
          lcd_gotoxy(10,1);
          printf(lcd_putc,"L= %lu",LDR); 
          lcd_gotoxy(0,2);
          printf(lcd_putc,"V= %luV",V);
          lcd_gotoxy(8,2);
          printf(lcd_putc,"I= %2.2fmA",I);
          delay_ms(1000);        
 }
 
 
      } //WHILE
                              
      } //MAIN


