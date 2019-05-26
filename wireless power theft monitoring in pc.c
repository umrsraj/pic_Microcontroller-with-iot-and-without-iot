/*
  *********RF(433MHZ) BASED DC MOTOR SPPED & DIRECTION CONTROLLING AND SPEED MONITORING ON LCD DISPLAY   *********** 
  B0 TO B4 = RF RECEIVER
  C0 TO C4 = L293D MOTOR DRIVER,
  B - PORT = LCD,
  C4 = LED1 
  C5 = LED2
*/

#include <16F73.h>
#FUSES HS,PUT
#use delay(clock=20M)
#use rs232  (baud = 9600, xmit=PIN_B0,rcv=PIN_B1,stream=BT) //for Bluetooth Interface

#include <flex_lcd.c>


unsigned int ct1 = 0; 
unsigned int ct2 = 0; 

//int16 duty_cycle=512;

void main()
{
   
    lcd_init();
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );
   
   output_high(pin_C3);
output_high(pin_C4);
output_high(pin_C5);
   delay_ms(1000);
   
   output_low(pin_C3);
output_low(pin_C4);
output_low(pin_C5);
   delay_ms(1000);
   
      
output_high(pin_C3);
output_high(pin_C4);
output_high(pin_C5);
   delay_ms(1000);
   
output_low(pin_C3);
output_low(pin_C4);
output_low(pin_C5);
   delay_ms(1000);
   
fprintf(BT,"Welcome to Wireless Power Theft Monitoring system with PC \r\n"); delay_ms(1000); 
   
    printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"    WIRELESS    ");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"  POWER  THEFT  ");
              delay_ms(20);
              
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"MONITORING SYSTEM");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"    USING PC    ");
              delay_ms(20);
   
            
   while(1)
   {   

 set_adc_channel(0);
      delay_ms(50);// delay built-in function call
      ct1 = Read_ADC();
   delay_ms(50);

 set_adc_channel(1);
      delay_ms(50);// delay built-in function call
      ct2 = Read_ADC();
   delay_ms(50);
   

if ((ct1<66)&&(ct2>5))

{
fprintf(BT,"******Power Theft Alert****** Plz Check \r\n"); delay_ms(2000); 
 
   printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"power theft alert");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"plz check");
              delay_ms(100);
}
else
{
fprintf(BT,"SYSTEM IS NORMAL \r\n"); delay_ms(1000); 

} 
   }  //WHILE 
}  //MAIN

