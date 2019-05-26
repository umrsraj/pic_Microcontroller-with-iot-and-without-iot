/********************************************************************************************************************
TITLE: RAILWAY CRACK DETECTION ROBOT USING GSM

A0 = IR SENSOR FOR CRACK DETECTION,
D6 = LED FOR CRACK DETECTION,
D5 LED FOR OBSATCLE SENSOR,
D2= BUZZER ALARM ,

***********************************************************************************************************************/
#include <16F877A.h>  //MICROCONTROLLER HEADER FILE
#FUSES   NOWDT, HS    //NO WATCH DOG TIMER ,HIGH SPEED 
#use     delay(clock=20000000)   //CRYSTAL FREQUENCY
#include "dc motor.c"    //DC MOTOR HEADER FILE
#include "flex_lcd.c"
#use rs232(baud=9600, xmit=PIN_B0, rcv=PIN_B1,stream=GSM)

void send_sms1()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"ATE0\r\n");
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */
fprintf(GSM,"AT+CNMI=1,2,0,0\r\n"); 
fprintf(GSM,"AT+CSMP=17,167,0,0\r\n"); 
delay_ms(1000);
fputc(0x0d,GSM);
delay_ms(1000);                                      
fprintf(GSM,"AT+CMGS=\"+917207530924\""); /*sends a carriage return */
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM,"VEHICLE STARTED...\r\n");
delay_ms(1500); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
}


void send_sms2()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"ATE0\r\n");
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */
fprintf(GSM,"AT+CNMI=1,2,0,0\r\n"); 
fprintf(GSM,"AT+CSMP=17,167,0,0\r\n"); 
delay_ms(1000);
fputc(0x0d,GSM);
delay_ms(1000);                                      
fprintf(GSM,"AT+CMGS=\"+917995517329\""); /*sends a carriage return */
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM,"VEHICLE STARTED...\r\n");
delay_ms(1500); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
}


void send_sms3()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"+917207530924\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM,"CRACK DETECTED @ TRACK:45***\r\n");
delay_ms(1000);
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
}


void send_sms4()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"+917995517329\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM,"CRACK DETECTED @ TRACK:45***\r\n");
delay_ms(1000);
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
}

void beep()
{
output_high(pin_e2);
delay_ms(700);
output_low(pin_e2);

}



void main()
{
    unsigned long ir;
   lcd_init();
 
   setup_port_a( ALL_ANALOG );
   setup_adc(ADC_CLOCK_INTERNAL);
  
lcd_init(); //Initialise LCD display
//CHECK UP
output_high(pin_d2);  //LED 1 ON
output_high(pin_d3);  //LED 2 ON
delay_ms(500);  
output_low(pin_d2);
output_low(pin_d3);
delay_ms(500); beep();
output_high(pin_d2);  //LED 1 ON
output_high(pin_d3);  //LED 2 ON
delay_ms(500);  
output_low(pin_d2);
output_low(pin_d3);
delay_ms(500);
send_sms1();
    lcd_putc('\f');
    lcd_gotoxy(0,1);
    printf(lcd_putc,"  RAILWAY CRACK  ");
    lcd_gotoxy(0,2);
    printf(lcd_putc,"DETECTION SYSTEM");
    delay_ms(2500);
    
     lcd_putc('\f');
    lcd_gotoxy(0,1);
    printf(lcd_putc," USIGN GSM TECHNOLOGY ");
    lcd_gotoxy(0,2);
    printf(lcd_putc,"----------------------");
    delay_ms(3500);
  send_sms2(); delay_ms(3500);

forword1();forword2();
//backword2();



//CONTIOUES LOOP ............................................................................
while(true) 
{
   //LDR PERCENTAGE.................... 
        set_adc_channel(0);
         delay_ms(10);
         ir = Read_ADC();   //read ldr adc value

//CRACK DETECTION SENSOR DETECTED
if(ir<50)
{
stop1(); //M1 STOP
stop2(); //M2 STOP
beep();
output_high(pin_d3);   //BUZZER ON
output_low(pin_d2);   //led ON
    lcd_putc('\f');
    lcd_gotoxy(1,1);
    printf(lcd_putc,"CRACK  DETECTED ");
    lcd_gotoxy(0,2);
    printf(lcd_putc,"@ NO=45.PLS CHECK*******");
     delay_ms(1500);
   send_sms3(); //SMS SENDING....
   lcd_putc('\f');
    lcd_gotoxy(1,1);
    printf(lcd_putc,"CRACK  DETECTED ");
    lcd_gotoxy(0,2);
    printf(lcd_putc,"SMS1 SENDING.....");
    delay_ms(4000);
    send_sms4(); //SMS SENDING....
   lcd_putc('\f');
    lcd_gotoxy(1,1);
    printf(lcd_putc,"CRACK  DETECTED ");
    lcd_gotoxy(0,2);
    printf(lcd_putc,"SMS2 SENDING.....");
    delay_ms(3500);
  
}//while(ir<50);

//NORMAL CONDITION................................
else
{
forword1();
forword2();
output_low(pin_d3);
output_high(pin_d2);
output_low(pin_e0);
    lcd_putc('\f');
    lcd_gotoxy(0,1);
    printf(lcd_putc," SYSTEM IS OK ");
    lcd_gotoxy(0,2);
    printf(lcd_putc,"VEHICLE MOVING.....");
    delay_ms(1000);
}
}//WHILE LOOP
}//MAIN LOOP 


