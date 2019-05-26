/****************************************************************************
TITLE: ANDROID BASED LCD NOTICE BOARD
PIC16F72,
LCD= B2 TO B7,
B0,B1 =BLUTOOTH,
BUZZER = C3,
LED INDICATOR = C4

*******************************************************************************/
#include <16F73.h> //Microcontroller used
#fuses hs,put,nowdt,protect
#use   delay  (clock=20000000) //Crystall Oscillator frequency
#include <string.h>
#use rs232  (baud = 9600, xmit=PIN_A1,rcv=PIN_A0,stream=BT) //for Bluetooth Interface
#include "flex_lcd.c"

int i;
char notice_data[90] = "Welcome to Android Operated Wireless LCD Message Display";
//char notice_data[90];
void start()
{
    lcd_putc('\f');
    lcd_gotoxy(1,1);
    printf(lcd_putc,"  ANDROID BASED ");
    lcd_gotoxy(1,2);
    printf(lcd_putc,"LCD NOTICE BOARD");
    delay_ms(3000);
  
}
  
void main()
{         
   
   lcd_init(); //Initialise LCD display
   start(); //show Intro message on LCD display
   
   char ch;
   //Microcontroller health check
   output_high(PIN_C3); //Buzzer ON
   delay_ms(600);
   output_low(PIN_C3); //Buzzer OFF
   
   output_high(PIN_C4); //LED ON
   delay_ms(600);
   output_low(PIN_C4); //LED OFF
   delay_ms(600);
   output_high(PIN_C4);
   delay_ms(600);
   output_low(PIN_C4);
   
   lcd_putc('\f');
    lcd_gotoxy(3,1);
    printf(lcd_putc,"  PLEASE  ");
    lcd_gotoxy(1,2);
    printf(lcd_putc,"SEND MESSAGE.....");
 
 while(1)
   {
     output_high(PIN_C4); //status indicator
     
   // fgets(notice_data);     //READ string value VALUE FROM BLUTOOTH MODULE

     // notice_data = fgets(BT);     //READ ZIGBEE VALUE FROM BLUTOOTH MODULE
     do 
     {
     ch= fgetc(BT);
     }while(ch!='*');
     i=0;
     do 
     {
     ch= fgetc(BT);
     notice_data[i++]=ch;
     }while(ch!='#');
     notice_data[--i]='\0';
     
      output_high(PIN_C3); //Buzzer ON
     delay_ms(500); //delay
     output_low(PIN_C3); //Buzzer OFF
 
     lcd_putc('\f'); //clear LCD display
     //lcd_send_byte(0,0x1E);
     lcd_gotoxy(1,1); // go to row 2 and column 1
     printf(lcd_putc,notice_data); //display college name
     //lcd_putc(notice_data);// 
     output_low(PIN_C4);
      for(i = 0; i < 80; i++)  // Shift display right 20 times (means 20characters right to left)
        {          
           delay_ms(200);
           lcd_send_byte(0,0x1E);  //right to left rotation 
                   
        }
    
   } //whi
}

