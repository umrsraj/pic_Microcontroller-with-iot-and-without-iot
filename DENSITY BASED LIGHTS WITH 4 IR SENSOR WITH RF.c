/************************************************************
PROJECT TITLE: DENSITY BASED TRAFFIC LIGHT CONTROL SYSTEM USING TWO IR SENSOR(WITH 8 LED'S)

PIC16F877A

IR SENSOR1 = A0(FOR LOW DENSITY),

IR SENSOR2 = A1(FOR HIGH DENSITY),

LCD= C0 TO D1   (LEFT SIDE)**********
RF RX= B0 TO B4   

D2,D3= READ,GREEN LED'S FOR EAST

C4,C5= READ,GREEN LED'S FOR WEST

C6,C7= READ,GREEN LED'S FOR NORTH

D4,D5= READ,GREEN LED'S FOR SOUTH

***********************************************************/
#include <16F877a.h>
#fuses  HS,NOWDT,PROTECT,brownout,put
#use delay  (clock=20000000)
#include "flex_C0-D1_lcd.c"

void check(void);
void main()
{
  
  lcd_init();
  
   printf(lcd_putc,"\f");
   lcd_gotoxy(1,1);
   printf(lcd_putc,"DENSITY BASED ");
   lcd_gotoxy(1,2);
   printf(lcd_putc," TRAFFI LIGHT ");
   delay_ms(2500);
   
   printf(lcd_putc,"\f");
   lcd_gotoxy(2,1);
   printf(lcd_putc,"CONTROL SYSTEM ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"**************");
   delay_ms(2500);
   
   
   //HEALTH CHECK UP
   output_high(PIN_D2);
   output_high(PIN_D3);
   output_high(PIN_C4);
   output_high(PIN_C5);
   output_high(PIN_C6);
   output_high(PIN_C7);
   output_high(PIN_D4);
   output_high(PIN_D5);
      delay_ms(500);
   output_low(PIN_D2);
   output_low(PIN_D3);
   output_low(PIN_C4);
   output_low(PIN_C5);
   output_low(PIN_C6);
   output_low(PIN_C7);
   output_low(PIN_D4);
   output_low(PIN_D5);
   delay_ms(500);
   
   output_high(PIN_D2);
   output_high(PIN_D3);
   output_high(PIN_C4);
   output_high(PIN_C5);
   output_high(PIN_C6);
   output_high(PIN_C7);
   output_high(PIN_D4);
   output_high(PIN_D5);
      delay_ms(500);
   output_low(PIN_D2);
   output_low(PIN_D3);
   output_low(PIN_C4);
   output_low(PIN_C5);
   output_low(PIN_C6);
   output_low(PIN_C7);
   output_low(PIN_D4);
   output_low(PIN_D5);
   delay_ms(500);
   
     //END HEALH CHECK UP
  
   printf(lcd_putc,"\f");
   lcd_gotoxy(0,1);
   printf(lcd_putc,"E:NRML ");
    lcd_gotoxy(9,1);
   printf(lcd_putc,"W:NRML ");
   
    lcd_gotoxy(0,2);
   printf(lcd_putc,"N:NRML ");
    lcd_gotoxy(9,2);
   printf(lcd_putc,"S:NRML ");
   delay_ms(2500);
  
  //CONTINOUS LOOP---------------------------------------
   while(1)
   {
   check();
   
  //1ST 
   output_low(PIN_D2);
   output_high(PIN_D3); //GREEN ON...................
   
   
   output_high(PIN_C4);
   output_low(PIN_C5); //GREEN
   
   output_high(PIN_C6); 
   output_low(PIN_C7); //GREEN
   
   output_high(PIN_D4);
   output_low(PIN_D5); //GREEN
   delay_ms(2000);  //2 min delay
   
   check();
   
   //2ND SIDE
   
   output_high(PIN_D2);
   output_low(PIN_D3); //GREEN ...................
   
   
   output_low(PIN_C4);
   output_high(PIN_C5); //GREEN   1 -------------------
   
   output_high(PIN_C6); 
   output_low(PIN_C7); //GREEN
   
   output_high(PIN_D4);
   output_low(PIN_D5); //GREEN
   delay_ms(2000);  //2 min delay
  
  
   check();
   
   //3RD SIDE
   
   output_high(PIN_D2);
   output_low(PIN_D3); //GREEN ON...................
   
   
   output_high(PIN_C4);
   output_low(PIN_C5); //GREEN
   
   output_low(PIN_C6); 
   output_high(PIN_C7); //GREEN ---------------------
   
   output_high(PIN_D4);
   output_low(PIN_D5); //GREEN
   delay_ms(2000);  //2 min delay
  check();
   
   //4th SIDE
   
   output_high(PIN_D2);
   output_low(PIN_D3); //GREEN ON...................
   
   
   output_high(PIN_C4);
   output_low(PIN_C5); //GREEN
   
   output_high(PIN_C6); 
   output_low(PIN_C7); //GREEN
   
   output_low(PIN_D4);
   output_high(PIN_D5); //GREEN
   delay_ms(2000);  //2 min delay
  
  
   check();
   

 } //WHILE LOOP
}  //MAIN LOOP



void check(void)
{

//1ST SIDE  EAST 
 if((input(pin_A0))||((!input(pin_B6))&&(input(pin_B7))))  
  //if(input(pin_A0))
{
   lcd_gotoxy(0,1);
   printf(lcd_putc,"E:FULL ");
   // lcd_gotoxy(9,1);
  // printf(lcd_putc,"W:NRML ");
   
   // lcd_gotoxy(0,2);
 //  printf(lcd_putc,"N:NRML ");
 //   lcd_gotoxy(9,2);
 //  printf(lcd_putc,"S:NRML ");
 
   output_low(PIN_D4);
   output_high(PIN_D5); //GREEN ON...................
   
   
   output_high(PIN_D2);
   output_low(PIN_D3); //GREEN
   
   output_high(PIN_C4); 
   output_low(PIN_C5); //GREEN
   
   output_high(PIN_C6);
   output_low(PIN_C7); //GREEN
   delay_ms(2000);  //2 min delay
   delay_ms(2000);  //2 min delay94454     
   delay_ms(2000);  //2 min delay
   delay_ms(2000);  //2 min delay
 
}




//2ND SIDE  EAST 
  if((input(pin_A1))||((!input(pin_B5))&&(input(pin_B7)))) 
 //  if(input(pin_A1))
{
    lcd_gotoxy(9,1);
   printf(lcd_putc,"W:FULL ");
   
   // lcd_gotoxy(0,2);
 //  printf(lcd_putc,"N:NRML ");
   // lcd_gotoxy(9,2);
   //printf(lcd_putc,"S:NRML ");
   
   output_low(PIN_C4);
   output_high(PIN_C5); //GREEN ON...................
   
   
   output_high(PIN_D2);
   output_low(PIN_D3); //GREEN
   
   output_high(PIN_C6); 
   output_low(PIN_C7); //GREEN
   
   output_high(PIN_D4);
   output_low(PIN_D5); //GREEN
   delay_ms(2000);  //2 min delay
   delay_ms(2000);  //2 min delay
   delay_ms(2000);  //2 min delay
   delay_ms(2000);  //2 min delay
   

}



//3rd side   

 if((input(pin_A2))||((!input(pin_B4))&&(input(pin_B7)))) 
 // if(input(pin_A2))
{
   //lcd_gotoxy(0,1);
  // printf(lcd_putc,"E:FULL ");
   // lcd_gotoxy(9,1);
  // printf(lcd_putc,"W:NRML ");
   
   lcd_gotoxy(0,2);
  printf(lcd_putc,"N:FULL ");
    //lcd_gotoxy(9,2);
  // printf(lcd_putc,"S:NRML ");
   
   output_low(PIN_C6); 
   output_high(PIN_C7); //GREEN
   
   output_high(PIN_C4);
   output_low(PIN_C5); //GREEN ON...................
     
   output_high(PIN_D2);
   output_low(PIN_D3); //GREEN
  
   
   output_high(PIN_D4);
   output_low(PIN_D5); //GREEN
   delay_ms(2000);  //2 min delay
   delay_ms(2000);  //2 min delay
   delay_ms(2000);  //2 min delay
   delay_ms(2000);  //2 min delay
}




 if((input(pin_A3))||((!input(pin_B3))&&(input(pin_B7)))) 
 //  if(input(pin_A3))
{
   
     // lcd_gotoxy(0,1);
  // printf(lcd_putc,"E:NRML ");
   // lcd_gotoxy(9,1);
   //printf(lcd_putc,"W:FULL ");
   
   // lcd_gotoxy(0,2);
  // printf(lcd_putc,"N:NRML ");
    lcd_gotoxy(9,2);
   printf(lcd_putc,"S:FULL ");

 
 
 
 
   
   output_low(PIN_D2);
   output_high(PIN_D3); //GREEN  on
    
   output_high(PIN_C4);
   output_low(PIN_C5); //GREEN 
   
   output_high(PIN_C6); 
   output_low(PIN_C7); //GREEN
   
   output_high(PIN_D4);
   output_low(PIN_D5); //GREEN
   delay_ms(2000);  //2 min delay
   delay_ms(2000);  //2 min delay
   delay_ms(2000);  //2 min delay
   delay_ms(2000);  //2 min delay
   

   
}


output_high(PIN_B6);output_high(PIN_B5);   output_high(PIN_B4);   output_high(PIN_B3);
output_low(PIN_B7); 
   
    lcd_gotoxy(0,1);
   printf(lcd_putc,"E:NRML ");
    lcd_gotoxy(9,1);
   printf(lcd_putc,"W:NRML ");
   
    lcd_gotoxy(0,2);
   printf(lcd_putc,"N:NRML ");
    lcd_gotoxy(9,2);
   printf(lcd_putc,"S:NRML ");
  
}




