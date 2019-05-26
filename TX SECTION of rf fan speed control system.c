/*****************************************************************************
TITLE:DEVELOPEMENT OF GAS AND FIRE DETECTION SYSTEM USING RF   (TX SECTION )
PIC16F877A
RF TX = B0 TO B4,
LCD= D7 TO GND,
D2=GREEN LED,
D3= RED LED,
D1=BUZZER,
A0= ALCOHOL SENSOR,
A1 = TEMP SENSOR,
****************************************************************************/
#include <16F73.h>
#fuses  HS,NOWDT,PROTECT,brownout,put
#use delay  (clock=20M)
#include <flexd7_lcd.c>

void buzzer()
{
output_high(pin_c3); //buzzer on
delay_ms(700);
output_low(pin_c3); //buzzer off
delay_ms(700);

}

/////////////////////////////////////////////////////////////////////////////////

//MAIN PROGRAMMING-------------------------------------------------------------
void main()
{
   float temp1,temp2,GAS,HUM;
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG ); 
   lcd_init();
  
   //HEALTH CHECK UP..........................................
   output_high(PIN_c3);  //BUZZER ON
   output_high(PIN_c4);  //GREEN LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(1000);
   output_low(PIN_c3);   //BUZZER OFF
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(1000);
     output_high(PIN_c3);  //BUZZER ON
   output_high(PIN_c4);  //GREEN LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(1000);
   output_low(PIN_c3);   //BUZZER OFF
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(1000);
   
   //ADC INITIALIZING 
   output_high (PIN_C4);
   output_low (PIN_C5);
//DISPLAY INITIAL MESSAGE
          lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(1,1);
         printf(lcd_putc,"WIRELESS FAN SPEED");
         lcd_gotoxy(3,2);
         printf(lcd_putc,"  CNTRL S/M");         
         delay_ms(1500); 
         lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"SYSTEM USING WRL ");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"SENSOR NETWORK ");         
                delay_ms(1200);
       //lcd_putc('\f');
      output_low(pin_B0);
      
          output_high(PIN_b1);   
          //output_high(PIN_b2);    output_high(PIN_b3);    output_high(PIN_b4);
//CONTINEOUS LOOP...........................................
  while(1)
  {
 set_adc_channel(0);       //TEMPERATURE ............................                      
      delay_ms(1);
      temp2=read_adc(); 
      delay_ms(1);
      temp1 = (temp2 * 100)/256;
      temp1 = temp1 * 5;
    
    
      //set_adc_channel(1);      //GAS LEAKAGE.................................                     
     // delay_ms(1);
     // GAS=read_adc(); 
     
//*****************************************************************
  
      if(temp1>55)
      {
      output_high(pin_C5); //RED LED ON
      output_low(pin_C4); //GREEN LED OFF
         output_high(pin_B1);
         output_low(pin_B0);     //rf
         delay_ms(10);
         output_low(pin_B1);
         delay_ms(100);output_high(PIN_b1);  
         //output_high(PIN_b2);output_high    (PIN_b3);    output_high(PIN_b4);
       buzzer(); 
       printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc," **TEMP HIGH** ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"PLEASE CHECK...");
      delay_ms(1500);
        printf(lcd_putc,"\f");
      lcd_gotoxy(3,1);
      printf(lcd_putc,"T=%2.0g%cC",temp1,0xDF);
      lcd_gotoxy(0,2);
      printf(lcd_putc,"**********************");
      delay_ms(1000);
      output_high(pin_B0);
      }      
     /*
     if(GAS>170)
      {
      output_high(pin_D3); //RED LED ON
      output_low(pin_D2); //GREEN LED OFF
      output_high(pin_B2);
         output_low(pin_B0);     //rf
         delay_ms(10);
         output_low(pin_B2);
         delay_ms(100);output_high(PIN_b1);    output_high(PIN_b2);    output_high(PIN_b3);    output_high(PIN_b4); 
               buzzer(); 
      printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"  GAS LEAKAGE ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"  ***ALERT***  ");
      delay_ms(500);
      output_high(pin_D3);    
      delay_ms(1000);
       printf(lcd_putc,"\f");
       lcd_gotoxy(3,1);
       printf(lcd_putc,"Ga=%f PPM",GAS);
      lcd_gotoxy(0,2);
      printf(lcd_putc,"**********************");
      delay_ms(1000);output_high(pin_B0); 
      }
      */
       
     // NORMAL MODE  
           if(temp1<55)
      {
       output_high(pin_c4); output_low(pin_c5); 
       output_high(pin_B0);
       output_low(pin_B1);
       
         printf(lcd_putc,"\f");
      lcd_gotoxy(3,1);
      printf(lcd_putc,"T=%2.0g%cC",temp1,0xDF);
      lcd_gotoxy(0,2);
      printf(lcd_putc,"Ga=%f PPM",GAS);
      delay_ms(500);// output_high(pin_B3);
       
       /*output_low(pin_d1);
      output_high(pin_B3);
              //rf
         delay_ms(10);
         output_low(pin_B3);
          delay_ms(100);output_high(PIN_b1);    output_high(PIN_b2);    output_high(PIN_b3);    output_high(PIN_b4); 
          output_high(pin_D2); //green led
      output_low(pin_D3);  //red led off
      output_low(pin_D1);
      printf(lcd_putc,"\f");
      lcd_gotoxy(3,1);
      printf(lcd_putc,"T=%2.0g%cC",temp1,0xDF);
      lcd_gotoxy(0,2);
      printf(lcd_putc,"Ga=%f PPM",GAS);
      delay_ms(500);// output_high(pin_B3);
      */
     }    
      
 
 }// WHILE......................................................................
  

}//MAIN

