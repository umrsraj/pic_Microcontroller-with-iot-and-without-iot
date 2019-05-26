/////////////////////////////////////////////////////////////////
/*
NAME:ELECTRONIC PASSPORT USING RFID AND PC

PIC16F877A
A0=RFID READER,
LCD= B2 TO B7,
D1= BUZZER,

B0,B1= MAZ232,

D2= GREEN LED,
D3= RED LED,
B0 =BUZZER
*/
///////////////////////////////////////////////////////////////////

#include <16f877A.h>
#fuses HS,NOWDT,NOPROTECT        
#use delay(clock=20000000)         // 40 MHz crystal on PCB
#use rs232  (baud = 9600,rcv=PIN_a0,stream=rfid)
#use rs232  (baud = 9600, xmit=PIN_B1,rcv=PIN_B0,stream=PC) //for Bluetooth Interface
#include "flex_lcd.c"


int16 i;
char value[12];//12 values of  RFID Tag ID


void show_projectname()
{
      lcd_putc('\f');
      lcd_gotoxy(0,1);
      printf(lcd_putc,"ELECTRONIC PASSPORT");
      lcd_gotoxy(3,2);
      printf(lcd_putc,"USING RFID ");
      delay_ms(3000);
             
  fprintf(PC,"\r\n  *****************************************  \r\n"); delay_ms(500);
  fprintf(PC,"\r\n     ELECTRONIC PASSPORT USING RFID \r\n"); delay_ms(300);
  fprintf(PC,"\r\n  *****************************************  \r\n");delay_ms(300);
       
}

void beep()
{
output_high(pin_d1);
delay_ms(1000);
output_low(pin_d1);
}

//MAIN PROGRAMMING.....................................................

void main()
 {
 lcd_init();

//HEALTH CHECK UP................
      output_high(pin_d2);  //GREEN LED ON
      output_high(pin_d3);  //RED LED ON
      delay_ms(500);
      output_low(pin_d2);  //GREEN LED OFF
      output_low(pin_d3);  //RED LED OFF
      delay_ms(500);
      output_high(pin_d2);  //GREEN LED ON
      output_high(pin_d3);  //RED LED ON
      delay_ms(500);
      output_low(pin_d2);  //GREEN LED OFF
      output_low(pin_d3);  //RED LED OFF
      delay_ms(500);
      show_projectname();                 //project name on lcd
      
      lcd_putc('\f');
      lcd_gotoxy(0,1);
      printf(lcd_putc,"PLEASE.. SCAN UR ");
      lcd_gotoxy(2,2);
      printf(lcd_putc,"RFID PASSPORT");
      delay_ms(1000);

    
   while (true)
   {
       

     for (i=0; i<12; i++) 
     { 
       value[i]=getc();
     output_toggle(pin_d2);  //GREEN LED OFF
     }
         
     lcd_putc('\f');
     lcd_gotoxy(1,1);
     printf(lcd_putc,"P.P ID=%s", value);
     lcd_gotoxy(1,2);
     printf(lcd_putc,"Checking Details......... ");
     fprintf(PC,"\r\n -----------------------------------------------------------  \r\n");delay_ms(500);
     fprintf(PC,"\r\n PASSPORT ID=%s\r\n",value);delay_ms(200);
     fprintf(PC,"\r\n Checking ...Details....");delay_ms(200);
     delay_ms(1000);

//preson 1
     if( value[7]=='D' && value[8]=='3' && value[9]=='7')    //VALID CARD       
     {
     output_high(pin_d2); output_low(pin_d3);
     lcd_putc('\f');
     lcd_gotoxy(0,1);
     printf(lcd_putc,"K.MADHAVI-LB NAGAR",);
     lcd_gotoxy(4,2);
     printf(lcd_putc,"AUTHORIZED ");
     delay_ms(1000);
     output_low(pin_d3);  //RED LED ON
     fprintf(PC,"\r\n N: K.MADHAVI,A: PLOT NO 263/5,ARUNODAYA COL,LB NAGAR  \r\n");delay_ms(500);
     fprintf(PC,"\r\n  PASSPORT AUTHORIZED  \r\n");delay_ms(500);
    fprintf(PC,"\r\n -----------------------------------------------------------  \r\n");delay_ms(500);
     }


//preson 2
     else if( value[7]=='4' && value[8]=='C' && value[9]=='4')    //VALID CARD       
     {
     output_high(pin_d2); output_low(pin_d3);
     lcd_putc('\f');
     lcd_gotoxy(1,1);
     printf(lcd_putc,"A.RAMESH -DSNR",);
     lcd_gotoxy(4,2);
     printf(lcd_putc,"AUTHORIZED ");
     delay_ms(1000);
     output_low(pin_d3);  //RED LED ON
     fprintf(PC,"\r\n N: A.RAMESH,A: PLOT NO 211/3,GREEN HILSS COL,DSNR  \r\n");delay_ms(500);
     fprintf(PC,"\r\n  PASSPORT AUTHORIZED  \r\n");delay_ms(500);
    fprintf(PC,"\r\n -----------------------------------------------------------  \r\n");delay_ms(500);
     }


//preson 3
     else if( value[7]=='6' && value[8]=='9' && value[9]=='9')    //VALID CARD       
     {
     output_high(pin_d2); output_low(pin_d3);
     lcd_putc('\f');
     lcd_gotoxy(0,1);
     printf(lcd_putc,"M.RANJITH -MADHAPUR",);
     lcd_gotoxy(4,2);
     printf(lcd_putc,"AUTHORIZED ");
     delay_ms(1000);
     output_low(pin_d3);  //RED LED ON
     fprintf(PC,"\r\n N: M.RANJITH,A: PLOT NO 36/11-2,RK COLONY,MADAPUR  \r\n");delay_ms(500);
     fprintf(PC,"\r\n  PASSPORT AUTHORIZED  \r\n");delay_ms(500);
    fprintf(PC,"\r\n -----------------------------------------------------------  \r\n");delay_ms(500);
     }
     

//preson 4
    else if( value[7]=='B' && value[8]=='2' && value[9]=='F')    //VALID CARD       
     {
     output_high(pin_d2); output_low(pin_d3);
     lcd_putc('\f');
     lcd_gotoxy(0,1);
     printf(lcd_putc,"S.RANI-KUKATPALLY",);
     lcd_gotoxy(4,2);
     printf(lcd_putc,"AUTHORIZED ");
     delay_ms(1000);
     output_low(pin_d3);  //RED LED ON
     fprintf(PC,"\r\n N: S.RANI,A: PLOT NO 311-1/3,YNK STREET,KUKATPALLY  \r\n");delay_ms(500);
     fprintf(PC,"\r\n  PASSPORT AUTHORIZED  \r\n");delay_ms(500);
    fprintf(PC,"\r\n -----------------------------------------------------------  \r\n");delay_ms(500);
     }     
     
    else
    {
     lcd_putc('\f');
     lcd_gotoxy(3,1);
     printf(lcd_putc,"UNAUTHORIZED ");
    lcd_gotoxy(1,2);
     printf(lcd_putc,"PASSPORT**ALERT******.");
    fprintf(PC,"\r\n UNAUTORIZED PASSPORT***PLS CEHECK*****\r\n");delay_ms(700);
   fprintf(PC,"\r\n -----------------------------------------------------------  \r\n");delay_ms(500);
    output_high(pin_d3);  //RED LED ON
    output_low(pin_D2);
    output_high(pin_D1);  //BUZZER ON
    delay_ms(100);
    delay_ms(100);
    delay_ms(3000);
    output_low(pin_D1);  //BUZZER ON
    }  //ELSE CLOSE
    
    
   }  //WHILE
 }  //MAIN
    
    


