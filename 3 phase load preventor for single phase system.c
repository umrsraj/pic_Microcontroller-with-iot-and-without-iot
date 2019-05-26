/***********************************
TITLE: SINGLE PHASING PREVENCTION FOR THREE PHASE LOAD

PIC16F73

LCD= B2 TO B7

A0=TEMP SENSOR,
A1= R PHASE,  //PUSH BUTTONS
A2= Y PHASE,
A3= B PHASE,

C7= RELAY 3 FOR B_PHASE

RED LED= C1(FOR R PHASE),
YELLOW LED= C2(FOR Y PHASE),
BLUE LED =C3(FOR B PHASE),
C4 = BUZZER,
********************************/
#include <16F877A.h>           //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include "flex_lcd.c"


void beep()
{
 output_high(pin_D1); 
      delay_ms(1000);
   output_low(pin_D1);

}


void main()
{
// int flag =0;
   lcd_init();
  float temp1,temp2;
  unsigned int r=0,y=0,b=0;
  
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );
   //setup_adc_ports(sAN0 | VSS_FVR);               // Configure AN0 pin as analog - Voltage reference: VSS - FVR(4.096V)
//  set_adc_channel(0);  
   
  //health check
   output_high(pin_c0);       // Health check
   output_high(pin_c1); 
   output_high(pin_C2);
   delay_ms(500);
   output_low(pin_c1);
   output_low(pin_c2);
   output_low(pin_C3);
   delay_ms(500);  
   output_high(pin_c0);       // Health check
   output_high(pin_c1); 
   output_high(pin_C2);
   delay_ms(500);
   output_low(pin_c1);
   output_low(pin_c2);
   output_low(pin_C3);
   delay_ms(500);    
 beep();
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"THREE PHASE LOAD    ");
   lcd_gotoxy(0,2);
   printf(lcd_putc," PROTECTION FROM");
   delay_ms(2000);
   
   printf(lcd_putc,"\f");
   lcd_gotoxy(0,1);
   printf(lcd_putc,"SINGLE PHASING");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"-------------------");
   delay_ms(2000);
   
   
  
     
  while(1)
  {

      
      set_adc_channel(0);       //TEMPERATURE ............................                      
      delay_ms(1);
      r=read_adc();
      set_adc_channel(1);       //TEMPERATURE ............................                      
      delay_ms(1);
      y=read_adc();
      set_adc_channel(2);       //TEMPERATURE ............................                      
      delay_ms(1);
     b=read_adc();
      /*
        printf(lcd_putc,"\f");
    lcd_gotoxy(0,1);
    printf(lcd_putc,"R=%u V",r);
     lcd_gotoxy(10,1);
    printf(lcd_putc,"Y=%u V",y);
  lcd_gotoxy(0,2);
    printf(lcd_putc,"B=%u V",B);delay_ms(500);
  */
 
  
  //IF THREE PHASES GONE
  //
 // if((!(input(pin_a1)))&& (!(input(pin_A2)))&&(!(input(pin_E1))))                //A0==0 & A1=1
  if((r<50)&& (y<50)&& (b<50))  
  {
   output_low(pin_C0); output_low(pin_C1);output_low(pin_c2);
   
    beep();
   output_low(pin_C7);output_low(pin_C6); output_low(pin_C5);//b_relay  OFF
  
    printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"THREE PHASES FAULT");
    lcd_gotoxy(3,2);
    printf(lcd_putc,"LOAD OFF");
   output_low(pin_C0);output_low(pin_C1);output_low(pin_C2);//b_relay  OFF
    
    //lcd_gotoxy(1,1);
    //printf(lcd_putc,"  R_PHASE CONNECTED");
      delay_ms(1000);  
    
  
  }
  
  
  
  //INDIVIDUAL PHASES GONE
  
  if(r<10)             //A0==0  R PHASE GONE
  {
   
    output_low(pin_C0);
  output_low(pin_C7); output_low(pin_C6); output_low(pin_C5);
 beep();
   
    printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"R-PHASES FAULT");
    lcd_gotoxy(3,2);
    printf(lcd_putc,"LOAD OFF");
    
    //lcd_gotoxy(1,1);
    //printf(lcd_putc,"  R_PHASE CONNECTED");
      delay_ms(1000);  
    
  
  }
  
  
  if(y<10)              //A0==0  y PHASE GONE
  {
     output_low(pin_C7);output_low(pin_C6);output_low(pin_C5);
   output_low(pin_C1);
 beep();
   
    printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"Y-PHASES FAULT");
    lcd_gotoxy(3,2);
    printf(lcd_putc,"LOAD OFF");
    
    //lcd_gotoxy(1,1);
    //printf(lcd_putc,"  R_PHASE CONNECTED");
      delay_ms(1000);  
    
  
  }
  
  
  //b-phase gone
  if(b<50)             //A0==0  R PHASE GONE
  {
   output_low(pin_C7);output_low(pin_C6);output_low(pin_C5);
output_low(pin_c2);
 beep();
    printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"B-PHASES FAULT");
    lcd_gotoxy(3,2);
    printf(lcd_putc,"LOAD OFF");
    
    //lcd_gotoxy(1,1);
    //printf(lcd_putc,"  R_PHASE CONNECTED");
      delay_ms(1000);  
    
  
  }
  
   //IF NO PHASE IS FAULT
 // if(((input(pin_a1)))&& ((input(pin_a2)))&&((input(pin_E1)))&&((temp1<60)&&(temp1>30)))                //A0==0 & A1=1
 if((r>200)&&(y>200)&&(b>200)) 
 {
     output_high(pin_C5); output_high(pin_C6);output_high(pin_c7);
     output_high(pin_C0); output_high(pin_C1);output_high(pin_c2);
    printf(lcd_putc,"\f");
    lcd_gotoxy(2,1);
    printf(lcd_putc,"SYSTEM IS OK");
     lcd_gotoxy(1,2);
      printf(lcd_putc,"---LOAD ON-----");
      delay_ms(1000);  
    
  }
  

    
    } //while close
}  //main close


