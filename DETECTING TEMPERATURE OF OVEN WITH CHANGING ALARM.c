/*
TITEL: DETECTING TEMPERATURE OF OVEN WITH CHANGING ALARM
A0= TEMP SENSOR,
LCD= B PORT,
C3= BUZZER,

C4,C5,C6 = 3 LED'S ,
C7 = RELAY
*/

#include <16F73.h>        //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include "flex_lcd.c"

void beep()
{
output_high(pin_c3);
delay_ms(500);
output_low(pin_c3);
delay_ms(500);
}

 //MAIN PROGRAMMING...........................................................................................................................
void main()
{
//int temp;
   float temp1,temp2;
   
    setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG ); 
  
     lcd_init();
     
     
      printf(lcd_putc,"\f");  //clear lcd display
      lcd_gotoxy(0,1);         //select col,row
      printf(lcd_putc,"DET TEMPERATURE OF ");
      lcd_gotoxy(0,2);
      printf(lcd_putc,"OVEN WITH CHARGING ");
      delay_ms(2000);
      
           printf(lcd_putc,"\f");  //clear lcd display
      lcd_gotoxy(2,1);         //select col,row
      printf(lcd_putc,"ALARM SOUND &  ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"LIGHT  INDICATOR");
      delay_ms(2000);
      
      output_high(pin_C4);output_high(pin_C5);output_high(pin_C6); beep();     
           delay_ms(500);
      output_low(pin_C4); output_low(pin_C5); output_low(pin_C6);
      delay_ms(500);
      
       output_high(pin_C4);output_high(pin_C5);output_high(pin_C6); beep();     
           delay_ms(500);
      output_low(pin_C4); output_low(pin_C5); output_low(pin_C6);
      delay_ms(500);
     
     
     
  printf(lcd_putc,"\f");


   while(TRUE)
   {
 //READ TEMPERATURE VALUE.......
      set_adc_channel(0);    //A0 ADC VALUE          
      delay_ms(1);
      temp1=read_adc();
      delay_ms(1);
      temp2 = (temp1 * 100)/256;
      temp2 = temp2 * 5;
      
      
      
          
      
      //comparing values.......................
  //LEVEL-1
     // if((temp2>35)&&(temp2<45))
       if((temp2>30)&&(temp2<33))
       {
      output_high(pin_c4);
      printf(lcd_putc,"\f");
      lcd_gotoxy(2,1);
      printf(lcd_putc,"OVEN TEMP=%2.0g%cC",temp2,0xDF);
      lcd_gotoxy(0,2);
      printf(lcd_putc,"LEVEL-1 --REACHED---");
             output_high(pin_C7);       // RELAY ON
        delay_ms(1000);
   
      }
      
      //TEMP LEV-2 REACHED
    // else  if((temp2>45)&&(temp2<65))
     else if((temp2>33)&&(temp2<36))
      {
      output_high(pin_c4); output_high(pin_c5);
      printf(lcd_putc,"\f");
      lcd_gotoxy(2,1);
      printf(lcd_putc,"OVEN TEMP=%2.0g%cC",temp2,0xDF);
      lcd_gotoxy(0,2);
      printf(lcd_putc,"LEVEL-2 --REACHED---");
           output_high(pin_C7);       // RELAY ON
        delay_ms(1000);
   
      } 
      
      
      //TEMP LEV-3 REACHED
     //else   if((temp2>65)&&(temp2<95))
     else  if((temp2>36)&&(temp2<40))
     {
      output_high(pin_c4); output_high(pin_c5); output_high(pin_c6);beep();
      printf(lcd_putc,"\f");
      lcd_gotoxy(2,1);
      printf(lcd_putc,"OVEN TEMP=%2.0g%cC",temp2,0xDF);
      lcd_gotoxy(0,2);
      printf(lcd_putc,"LEVEL-3 --REACHED---");
              output_low(pin_C7);       // RELAY ON
        delay_ms(6000);
   
      } 
            
    
    //OVER TEMP
      //TEMP LEV-3 REACHED
   //  else   if((temp2>100)&&(temp2<150))
    else if((temp2>40)&&(temp2<100))
    {
      output_high(pin_c4); output_high(pin_c5); output_high(pin_c6);output_high(pin_c3);
      printf(lcd_putc,"\f");
      lcd_gotoxy(2,1);
      printf(lcd_putc,"OVEN TEMP=%2.0g%cC",temp2,0xDF);
      lcd_gotoxy(0,2);
      printf(lcd_putc,"OVER TEMPE --REACHED---");
              output_low(pin_C7);       // RELAY ON
        delay_ms(6000);output_high(pin_c3);
  //  delay_ms(6000);
      } 
         
     else
      {
      
      printf(lcd_putc,"\f");
      lcd_gotoxy(2,1);
      printf(lcd_putc,"OVEN TEMP=%2.0g%cC",temp2,0xDF);
      lcd_gotoxy(2,2);
      printf(lcd_putc,"--NORMAL MLODE--");
      output_low(pin_C4);      
      output_low(pin_C5);      
      output_low(pin_C6);  
       output_high(pin_C7);  //RELAY ON
         delay_ms(1000);
   
      }
   }
}
  

