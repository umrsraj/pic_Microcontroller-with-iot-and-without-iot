/*
IOT BASED GEREEN HOUSE PARAMETERS MONITORING SYSTEM (TEMP,LDR,SOIL,
*/

#include <16F873.h>           //Microcontroller Used
#fuses HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include "flex_lcd.c"

void show_projectname()
{
      lcd_putc('\f');
      lcd_gotoxy(1,1);
      printf(lcd_putc,"    ENVIRONMENT   ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"MONITORING SYSTEM ");
      delay_ms(2000);
      lcd_putc('\f');
      lcd_gotoxy(1,1);
      printf(lcd_putc,"   PROJECT BY     ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"   CVR STUDENT    ");
      delay_ms(2000);
      
}
void main()
{
   float temp1,temp2,soil1,soil2,humidity;
    
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );
    
   lcd_init(); 
   
   show_projectname(); 
   
   output_high(pin_C4);
   output_high(pin_C5);
   delay_ms(500);
   output_low(pin_C4);
    output_low(pin_C5);
   delay_ms(500);
   output_high(pin_C4);
    output_high(pin_C5);
   delay_ms(500);
   output_low(pin_C4);
   output_low(pin_C5);
   delay_ms(500);
 
      while(true)
     {
      set_adc_channel(0);                           
      delay_ms(1);
      temp2=read_adc(); 
      delay_ms(1);
      //convert adc to temp
      temp1 = (temp2 * 100)/256;
      temp1 = temp1 * 5;
      
      set_adc_channel(2); //humidity sensor                          
      delay_ms(1);
      humidity=read_adc(); 
  
      set_adc_channel(1); //soil sensor
      delay_ms(1);
      soil1=read_adc();
       
      set_adc_channel(3); //soil sensor
      delay_ms(1);
      soil2=read_adc();
      
     
   
      
 ///////////////////////////////////////////////////     
  if(input(pin_c3))//night mode
  {
  if(temp1>=60)
  {
      lcd_putc('\f');
      lcd_gotoxy(1,1);
      printf(lcd_putc,"  Temp high  ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"  Night mode    ");
      delay_ms(2000);
      output_low(pin_c7);//relay off
      output_high(pin_c5);//buzzer
    //  output_high(pin_c4);  //led on
      
  }
  else if(soil1>=50&&soil2>=50)
  {
        output_low(pin_c7);  //led on
        lcd_putc('\f');
        lcd_gotoxy(1,1);
        printf(lcd_putc,"    MOTOR OFF    ");
        lcd_gotoxy(1,2);
        printf(lcd_putc,"    Night mode    ");
        delay_ms(2000);
      
  }
  else
  {
  output_high(pin_c7);//relay on
  output_low(pin_c5);//buzzer off
  
     
      
  lcd_putc('\f');//display temp on lcd
  lcd_gotoxy(1,1);
  printf(lcd_putc,"T= %2.0g%Cc",temp1,0xDF);
  lcd_gotoxy(10,1);
  printf(lcd_putc,"H=%f",humidity);
    lcd_gotoxy(1,2);
      printf(lcd_putc,"    Night mode    ");
  delay_ms(500);
  }
  }
  
  if(!input(pin_c3))//day mode
  {
  if(temp1>=60)
  {
      lcd_putc('\f');
      lcd_gotoxy(1,1);
      printf(lcd_putc,"  Temp high  ");
        lcd_gotoxy(1,2);
      printf(lcd_putc,"  Day mode    ");
      delay_ms(2000);
      output_low(pin_c7);//relay off
      output_high(pin_c5);//buzzer
    //  output_high(pin_c4);  //led on
      
  }
  else if(soil1>=50&&soil2>=50)
  {
        output_low(pin_c7);  //led on
        lcd_putc('\f');
        lcd_gotoxy(1,1);
        printf(lcd_putc,"    MOTOR OFF   ");
        lcd_gotoxy(1,2);
      printf(lcd_putc,"    Day mode    ");
        delay_ms(2000);
        
  }
    else
  {
  output_high(pin_c7);//relay on
  output_low(pin_c5);//buzzer off
  
     
  lcd_putc('\f');//display temp on lcd
  lcd_gotoxy(1,1);
  printf(lcd_putc,"T= %2.0g%Cc",temp1,0xDF);
  lcd_gotoxy(10,1);
  printf(lcd_putc,"H=%f",humidity);
  lcd_gotoxy(1,2);
  printf(lcd_putc,"    Day mode    ");
  delay_ms(500);
  /*
  lcd_gotoxy(1,2);
  printf(lcd_putc,"s1=%f",soil1);
   lcd_gotoxy(7,2);
  printf(lcd_putc,"s2=%f",soil2);
  delay_ms(1000);
  */

  }
  }
  
  

   }
}
    



