/******************************************************************************************
TITLE: RAILWAY GATE CONTROL SYSTEM WITH VIBRATION SENSOR AND 3 IR SENSORS
PIC16F77A,

IR1 = A0
IR2 = A1
IR3 = A2

VIBRATION SENSOR = E2

GATE = C0,C1

BUZZER = D1
LCD = B-PORT
G LED = D2
R LED = D3

*******************************************************************************************/
#include <16F877a.h>
#FUSES HS,PUT
#use delay(clock=20M)
#include <flex_lcd.c>

unsigned int s1 = 0;
unsigned int s2 = 0;
unsigned int s3 = 0;
unsigned int v = 0;

unsigned int flag = 0;
unsigned int i = 0;

#define ir1 pin_a0
#define ir2 pin_a1
#define ir3 pin_a2 

#define vib pin_e2

#define buzzer pin_d1

#define m11 pin_c0
#define m12 pin_c1

#define gled pin_d2
#define rled pin_d3

void check ()
{

 set_adc_channel(2);
      delay_ms(50);// delay built-in function call
      s3 = Read_ADC();                   // A/D read functions- built-in         
       delay_ms(1);
       
if (s3 >90)
{
output_high(buzzer);
}
else
{
output_low(buzzer);
}

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
   
  output_high(gled);
  output_high(rled);
  output_high(buzzer);
  delay_ms(600);
   
  output_low(gled);
  output_low(rled);
  output_low(buzzer);
  delay_ms(600);
  
  output_high(gled);
  output_high(rled);
  output_high(buzzer);
  delay_ms(600);
   
  output_low(gled);
  output_low(rled);
  output_low(buzzer);
  delay_ms(6);
   
                
  //display initial messsage ....................................
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"AUTOMATIC RAILWAY");
              lcd_gotoxy(0,2);
              printf(lcd_putc," GATE CNTRL S/M ");
              delay_ms(1500);
           
    while(TRUE)
    {
        
      set_adc_channel(0);
      delay_ms(50);// delay built-in function call
      s1 = Read_ADC();                   // A/D read functions- built-in         
       delay_ms(10);     
      
      set_adc_channel(1);
      delay_ms(50);// delay built-in function call
      s2 = Read_ADC();                   // A/D read functions- built-in         
       delay_ms(10);
      
      set_adc_channel(2);
      delay_ms(50);// delay built-in function call
      s3 = Read_ADC();                   // A/D read functions- built-in         
       delay_ms(10);
  
   set_adc_channel(7);
      delay_ms(50);// delay built-in function call
      v = Read_ADC();                   // A/D read functions- built-in         
       delay_ms(100);


 if((s1 > 60)&&(flag==0)&&(v<160)) 
  {
 
  
     output_high(rled);
     output_low(gled);
     flag=1;
 
  
     check();
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"  GATE OPENING  ");
              lcd_gotoxy(1,2);
              printf(lcd_putc,">>----------->>>");
              
              output_high(m11);
              output_low(m12);
              delay_ms(1500);
              output_low(m11);
              output_low(m12);
              
              delay_ms(2000);
           
  }
   

else  if((s2 > 60)&&(flag==1)&&(v<160))
   {
     output_high(rled);
     output_low(gled);
     flag=0;
 
  
     check();
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"  GATE CLOSING  ");
              lcd_gotoxy(1,2);
              printf(lcd_putc,"<<<-----------<<");
              
              output_high(m12);
              output_low(m11);
              delay_ms(1500);
              output_low(m11);
              output_low(m12);
              
              delay_ms(2000);
           
  }


   else 
   {
   
     output_high(gled);
     output_low(rled);
     
   output_low(buzzer);
   
    printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"SYSTEM IS NORMAL");
              lcd_gotoxy(1,2);
              printf(lcd_putc,"****************");
              delay_ms(300);
            
   
   }
    
          
           
    } //while loop
}  //main loop

