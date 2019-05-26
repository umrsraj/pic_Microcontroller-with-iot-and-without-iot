/*****************************************************************************
TITLE:  DRIVER GAZE TRACKING AND EYES OF THE ROAD TX SECTION
TX BOARD
PIC16F877A
LCD=B2 TO B7
ZIGBEE = B0,B1  MAX 232

A0= GAS SENSOR,
A1= IR SENSOR,A2= VIBRATOR SWITHCH,

BUZZER =D1,
D2= RED LED,
D3 = GREEN LED

C0 = EYE BLINK SENSOR .

********************************************************************************/
#include <16F877A.h>        //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
//#use rs232(baud=9600, xmit=PIN_B1, rcv=PIN_B0,stream=zigbee)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7,stream=zigbee) 
#include "flex_lcd.c"


char ch='x'; //to get data from Zigbee


// inactive the following command and to see what will it happen?   
//#priority  TIMER2, TIMER1,  TIMER0, rda  //set interrupt priority - timer2, timer0, timer1, rs232 receive 
#priority  rda , TIMER1,TIMER2  
#int_rda             // #INT_RDA -- RS232 receive data available   
void serial_isr()   
{   
    ch = getc(zigbee);
      
}   
void buzzer()
{
output_high(pin_D1);
delay_ms(1000);
output_low(pin_D1);
delay_ms(1000);
}

//MAIN PROGRAMMING....................................
void main()
{
//int temp;
   
   unsigned int16 value=1;
   //unsigned int16 value; //EYE BLINK
   float ALC,IR;
  // char ch;
 //unsigned int16 value=0;  
 
     enable_interrupts(int_rda);                  // RS232 receive data available   
    enable_interrupts(global);  
  
  
   //COUNTER 
  // set_timer1(0);
   //setup_timer_1(t1_external | T1_DIV_BY_1);//c0
 //PWM CONTROL
// setup_timer_2(T2_DIV_BY_16, 127, 1);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG ); 
  
  
     lcd_init();
          
  
//DISPLAY INITIAL MESSAGE
          lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(2,1);
         printf(lcd_putc,"DRIVER GAZE ");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"TRACKING EYES OFF ");         
         delay_ms(2000); 
         lcd_putc('\f');
         lcd_gotoxy(0,1);
         printf(lcd_putc,"THE ROAD DETECTION");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"-----SYSTEM------ ");         
        
        delay_ms(3000);
       //lcd_putc('\f');
      
  //    printf(lcd_putc,"\f");
 //fprintf(zigbee,"**************************************************************\r\n");
 //fprintf(zigbee,"ZIGBEE BASED INTELLIGENT SECURITY FOR COAL MINE WORKERS \r\n");
 //fprintf(zigbee,"**************************************************************\r\n");
//!  delay_ms(1000);
     
      output_high(pin_D1);   //BUZZER ON
      output_high(pin_D2);       // Health check        
      output_high(pin_D3);
      delay_ms(500);
      output_low(pin_D1);  //BUZZER OFF
      output_low(pin_D2);
      output_low(pin_D3);
      delay_ms(500);
      
      output_high(pin_D1);   //BUZZER ON
      output_high(pin_D2);       // Health check        
      output_high(pin_D3);
      delay_ms(500);
      output_low(pin_D1);  //BUZZER OFF
      output_low(pin_D2);
      output_low(pin_D3);
      delay_ms(500);
      
     
 
   while(TRUE)
   {
       set_adc_channel(0);      //GAS LEAKAGE.................................                     
      delay_ms(50);
      ALC=read_adc(); 
      
   //   set_adc_channel(1);      //HUMIDITY .................................
    //  delay_ms(50);
    //  IR=read_adc();
                    
    
       set_timer1(0);   
      setup_timer_1(t1_external | T1_DIV_BY_1);//c0
      delay_ms(1000);         
   
    setup_timer_1(T1_DISABLED);
    value=get_timer1();
      
      
      lcd_putc('\f');         //Clear LCD
      lcd_gotoxy(1,1);
      printf(lcd_putc,"%Lu" ,value);
      
           delay_ms(500);
 
       //NORMAL MODE
   // if((ALC<220)&&(IR>50)&&(value>=1)&&(T>=50))
    if((ALC<220)&&(value>=1))
  
 // else 
  {
      output_high(pin_D2); //green led
      output_low(pin_D3);  //red led off
      output_low(pin_D1);
       output_high(pin_D7);
   
         lcd_putc('\f');  //FORMATE LCD DISPLAY
         lcd_gotoxy(1,1);
         printf(lcd_putc,"SYSTM IS OK");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"VEHICLE MOVING..... ");         
         delay_ms(1000); 
         
     }
     
     
 
 
 //else
 {
          
  
   //  ch=fgetc(zigbee);
              if(ch =='1')
        {
         output_low(pin_D7);
      output_high(pin_D3); //RED LED ON
      output_low(pin_D2); //GREEN LED OFF
           buzzer(); 
        //putc('a');
        printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"EYES OFF THE ROAD");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"VEHICLE STOP*****");
      delay_ms(500);
      ch= 'x';
        
        }
       
           
      if(ALC>220)
      {    output_low(pin_D7);
      output_high(pin_D3); //RED LED ON
      output_low(pin_D2); //GREEN LED OFF
           buzzer(); 
        //putc('a');
        printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc," ALCOHOL DETECTED");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"VEHICLE STOP*****");
      delay_ms(500);
   //  fprintf(zigbee,"TEMP HIGH***** PLEASE CHECK******\r\n");
  
    
//fprintf(zigbee,"a\r\n");
      
      }      
 
 /*if(IR<30)
      {    output_low(pin_D7);
      output_high(pin_D3); //RED LED ON
      output_low(pin_D2); //GREEN LED OFF
           buzzer(); 
      printf(lcd_putc,"\f");
      lcd_gotoxy(2,1);
      printf(lcd_putc,"DRIVER IS NOT  ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"SEATING POSITION");
       delay_ms(1000);
 
  //   fprintf(zigbee,"GAS ALERT**** PLEASE CHECK******\r\n");
      
      }
    */
    
  
    
    
     //eye blink sensor detect.....................................
    
      if(value<1)
      {
     
      output_low(pin_D7);
      output_high(pin_D3); //RED LED ON
      output_low(pin_D2); //GREEN LED OFF
           buzzer(); 
           printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"DROWSY DETECTED***"); 
      lcd_gotoxy(1,2);
      printf(lcd_putc,"VEHICLE HAS STOP"); 
        // buzzer();
      delay_ms(4000); 
      }
  
  
 }   
      } //WHILE
                              
      } //MAIN


