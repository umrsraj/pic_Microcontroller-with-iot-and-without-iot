
/******************************************************************************************
TITLE: zigbee based intelligent helmet for coal mine
PIC16F877a,

temp = A0
gas = A1
buzzer = D1
LCD = B PORT 
G LED = d2
R LED = d3

*******************************************************************************************/
#include <16f877A.h>
#fuses HS,PUT,NOWDT,NOPROTECT
#use delay(clock=20000000)
#use rs232(baud=9600,xmit=pin_b0,rcv=pin_b1,stream=serial)  //zigbee data receive
//#define ADC=8
#include "flex_lcd.c"

unsigned int gas = 0;
unsigned int temp = 0;
unsigned int wat = 0;
unsigned int H = 0;
unsigned int W = 0;

float temp1;
float temp2;

void beep ()
{
output_high(pin_d1);delay_ms(1500);
output_low(pin_d1);
}

void main() 
{


   lcd_init();
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );
   
    // ext_int_edge(H_TO_L);       // Interrupt on falling edge of RB0/INT pin
//  ext_int_edge(L_TO_H);       // Interrupt on falling edge of RB0/INT pin
  //clear_interrupt(INT_EXT);   // Clear RB0/INT external interrupt flag bit
  //enable_interrupts(INT_EXT); // Enable RB0/INT external interrupt
  //enable_interrupts(GLOBAL);  // Enable all unmasked interrupt
   
   
output_high(pin_d2);
output_high(pin_d3);
output_high(pin_d1);
   delay_ms(500);
   
output_low(pin_d2);
output_low(pin_d3);
output_low(pin_d1);
 delay_ms(500);
      
output_high(pin_d2);
output_high(pin_d3);
output_high(pin_d1);
   delay_ms(500);
   
output_low(pin_d2);
output_low(pin_d3);
output_low(pin_d1);
 delay_ms(500);
   
  //display initial messsage ....................................
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"  ZIGBEE BASED  ");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"   INTELLIGENT  ");
              delay_ms(1700);
        
           printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"   HELMET FOR   ");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"   COAL MINES   ");
              delay_ms(1700);
           
            
           
           fprintf(serial,"\r\n ZIGBEE BASED INTELLIGENT HELMET FOR COAL MINE \r\n"); delay_ms(1500);
           
    while(TRUE)
    {
        set_adc_channel(0);       //TEMPERATURE ............................                      
      delay_ms(1);
      temp2=read_adc(); 
      delay_ms(1);
      temp1 = (temp2 * 100)/256;
      temp1 = temp1 * 5;
        
        
        
      set_adc_channel(1);
      delay_ms(50);// delay built-in function call
      gas = Read_ADC();                   // A/D read functions- built-in         
      delay_ms(1);
      
       
     

if (temp1>55)
{
   output_low(pin_d2);
   output_high(pin_d3);
   
    printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"TEMPERATURE ALERT");
              lcd_gotoxy(1,2);
              printf(lcd_putc,"***PLZ CHECK***");
              //delay_ms(1500);    
             
             output_high(pin_d1);
             
                 fprintf(serial,"\r\n **** Temperature Alert **** \r\n"); delay_ms(1500);
   fprintf(serial,"\r\n Temp : %2.2f\r\n",temp1); delay_ms(1500);
              output_low(pin_d1);
              
}
else if (gas>247)
{
   output_low(pin_d2);
   output_high(pin_d3);
   
  
 //  fprintf(serial,"\r\n %2.2f\r\n",temp1); delay_ms(1500);
   
    printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"   GAS ALERT   ");
              lcd_gotoxy(1,2);
              printf(lcd_putc,"***PLZ CHECK***");
              
               output_high(pin_d1);
              
                fprintf(serial,"\r\n **** Gas Alert **** \r\n"); delay_ms(1500);
               fprintf(serial,"\r\n Gas : %u\r\n",gas); delay_ms(1500);
      
       output_low(pin_d1);
}



   else 
   {
   
   output_high(pin_d2);
output_low(pin_d3);
 // fprintf(serial,"\r\n w \r\n"); delay_ms(500);

 
    printf(lcd_putc,"\f");
    lcd_gotoxy(0,1);
    printf(lcd_putc,"T= %2.2f",temp1);
    lcd_gotoxy(9,1);
    printf(lcd_putc,"G= %u ",gas);
   
    
     fprintf(serial,"\r\n SYSTEM IS NORMAL  \r\n"); delay_ms(500);
    delay_ms(100);
              
   
   }
    
           
           
    } //while loop
}  //main loop

