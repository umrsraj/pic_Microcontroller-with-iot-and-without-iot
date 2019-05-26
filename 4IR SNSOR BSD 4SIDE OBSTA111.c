/********************************************************************************************************************
TITLE: 4 IR SENSORS BSD 4 SIDE OBSTACLE AVOID DETECTION ROBOT
A0,A1,A2,B0 = 4 IR SENSORS.
L293D MOTOR DRIVER= C0 TO GND.
D2,D3,C4,C5= 4 LED'S,
LCD= B PORT,
E2= BUZZER,
***********************************************************************************************************************/
#include <16F877A.h>
#FUSES   NOWDT, HS
#use     delay(clock=20000000)
#include "flex_lcd.c"
#include "dc motor.c"

void beep()
{
output_high(pin_e2);
delay_ms(1000);
output_low(pin_e2);
delay_ms(200);
}

void main() 
{
//forword1();forword2();
output_high(pin_d2);
output_high(pin_d3);  // buzzer
output_high(pin_c4);
output_high(pin_c5);
delay_ms(500);
output_low(pin_d2);
output_low(pin_d3);
output_low(pin_c4);
output_low(pin_c5);
delay_ms(500);
output_high(pin_d2);
output_high(pin_d3);  // buzzer
output_high(pin_c4);
output_high(pin_c5);
delay_ms(500);
output_low(pin_d2);
output_low(pin_d3);
output_low(pin_c4);
output_low(pin_c5);
delay_ms(500);
beep();
   lcd_init();  
                              // power on delay  
   lcd_putc('\f');         //Clear LCD 
   lcd_gotoxy(0,1);
   printf(lcd_putc,"AUTOMATIC ALL-SIDES ");
   lcd_gotoxy(0,1);
   printf(lcd_putc,"OBSTACLE AVOID ROBOT");
   delay_ms(3000);
//stop1();stop2();   
while(1)
{
//case1 for detect obastacle alert.............................

//1st front sensor detect
 if(input(pin_a0))
{
backword1();  //reverse moving...
backword2();
output_high(pin_d2);  
//beep();beep();
delay_ms(100);
output_low(pin_d2); 
}


//2nd BACK sensor detect
 if(input(pin_a1))
{

forword1();forword2();//beep();
output_high(pin_d3);  
delay_ms(100);
output_low(pin_d3); 
}

//3rd LEFT sensor detect
 if(input(pin_a2))
{
forword1();backword2();//beep();
output_high(pin_C4);  
delay_ms(100);
output_low(pin_C4); 
}

//4TH RIGHT sensor detect
 if(input(pin_b0))
{
backword1();forword2();//beep();
output_high(pin_C5);  
delay_ms(100);
output_low(pin_C5); 
}

//IF ALL SENSORS OFF
 if((!input(pin_a0))&&(!input(pin_a1))&&(!input(pin_a2))&&(!input(pin_b0)))
{
forword1();forword2();
output_high(pin_d2);  
delay_ms(100);
output_low(pin_d2); 
output_low(pin_e2); //buzzer off
}

// if fornt and back sensor detect
 if((input(pin_A0))&&(input(pin_A1)))
{
backword1();forword2();//beep();
output_high(pin_D2);output_high(pin_D3);  
delay_ms(100);
output_low(pin_D2); output_low(pin_D3); 
}


}//while loop
}//main loop 

