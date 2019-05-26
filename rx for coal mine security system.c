/////////////////////////////////////////////////////////////////
/*
NAME: RFID BASED AUTOMATIC TOLL COLLECTION SYSTEM(WITH RS 50,100,150,200)
PIC16F877A
A0=RFID READER,
LCD= B2 TO B7,
GSM= B0,B1
L293D= C0 TO D1,SUP,GND,

D2= GREEN LED,
D3= RED LED,
B0 =BUZZER
*/
///////////////////////////////////////////////////////////////////

//#include <16f73.h>
#include <16f877A.h>
#include <stdlib.h>
#include <string.h>
#fuses HS,NOWDT,PROTECT,brownout,put
#use delay  (clock=20M)  //CLOCK FREQUENCY
#use rs232 (baud = 9600, xmit=PIN_B0, rcv=PIN_B1,stream=PC)
#use rs232(baud=9600, xmit=PIN_A1, rcv=PIN_A0,stream=GSM)  //   INTERRUPT CODDE
#include <flex_lcd.c>  //LCD HEADER
//char notice_data[90];
//unsigned int l=0;
char ch;
 //unsigned int16 cnt=0,ct=0,bal=0;

///////////////////////////////////////////
//int i=0;
//units-------
//char units1[3] = "50";
//char units2[3] = "70";
  
  
void show_projectname()
{printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"   WELCOME TO   ");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"   DESIGN AND   ");
              delay_ms(1700);
        
           printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"CONSTRUCTION OF");
              lcd_gotoxy(0,2);
              printf(lcd_putc," HIGH SECURITY ");
              delay_ms(1700);
           
              printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc," ALERT S/M FOR ");
              lcd_gotoxy(0,2);
              printf(lcd_putc,"  COAL MINES   ");
              delay_ms(1700);
           
}

void beep()
{
output_high(pin_C3);
delay_ms(1000);
output_low(pin_C3);

}

//TEST MESSAGE
void send_sms()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"ATE0\r\n");
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */
fputc(0x0d,GSM); 
//fprintf(GSM,"AT+CNMI=1,2,0,0\r\n"); 
//fputc(0x0d,GSM); 
//fprintf(GSM,"AT+CSMP=17,167,0,0\r\n"); 
//delay_ms(1000);
//fputc(0x0d,GSM);
delay_ms(1000);

/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9515226006\"");   /////////////////////////////////////////////////
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(2500); 

fprintf(GSM,"WELCOME!! COAL MINE SECURITY SYSTEM \r\n");delay_ms(200); 
//fprintf(GSM,"WITH GSM \r\n");
delay_ms(4000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(1000); 
}

//AFTER RECHARGE SMS SENT---------------
void send_smstemp()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"ATE0\r\n");
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */
fputc(0x0d,GSM); 
//fprintf(GSM,"AT+CNMI=1,2,0,0\r\n"); 
//fputc(0x0d,GSM); 
//fprintf(GSM,"AT+CSMP=17,167,0,0\r\n"); 
//delay_ms(1000);
//fputc(0x0d,GSM);
delay_ms(1000);

/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9515226006\"");   /////////////////////////////////////////////////
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(2500); 

fprintf(GSM,"TEMPERATURE ALERT PLZ CHECK\r\n");delay_ms(200); 
//fprintf(GSM,"WITH GSM \r\n");
delay_ms(4000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(1000); 
}

//low balance---------------
void  send_smsgas()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"ATE0\r\n");
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */
fputc(0x0d,GSM); 
//fprintf(GSM,"AT+CNMI=1,2,0,0\r\n"); 
//fputc(0x0d,GSM); 
//fprintf(GSM,"AT+CSMP=17,167,0,0\r\n"); 
//delay_ms(1000);
//fputc(0x0d,GSM);
delay_ms(1000);

/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9515226006\"");   /////////////////////////////////////////////////
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(2500); 

fprintf(GSM,"GAS ALERT PLEASE CHECK\r\n");delay_ms(200); 
//fprintf(GSM,"WITH GSM \r\n");
delay_ms(4000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(1000); 
}

//BALANCE ZERO = LOAD OFF---------------
void send_smshum()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"ATE0\r\n");
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */
fputc(0x0d,GSM); 
//fprintf(GSM,"AT+CNMI=1,2,0,0\r\n"); 
//fputc(0x0d,GSM); 
//fprintf(GSM,"AT+CSMP=17,167,0,0\r\n"); 
//delay_ms(1000);
//fputc(0x0d,GSM);
delay_ms(1000);

/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9515226006\"");   /////////////////////////////////////////////////
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(2500); 

fprintf(GSM,"HUMIDITY ALERT PLEASE CHECK\r\n");delay_ms(200); 
//fprintf(GSM,"WITH GSM \r\n");
delay_ms(4000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(1000); 
}
send_smswat()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"ATE0\r\n");
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */
fputc(0x0d,GSM); 
//fprintf(GSM,"AT+CNMI=1,2,0,0\r\n"); 
//fputc(0x0d,GSM); 
//fprintf(GSM,"AT+CSMP=17,167,0,0\r\n"); 
//delay_ms(1000);
//fputc(0x0d,GSM);
delay_ms(1000);

/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9515226006\"");   /////////////////////////////////////////////////
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(2500); 

fprintf(GSM,"WATER LEVEL ALERT PLEASE CHECK\r\n");delay_ms(200); 
//fprintf(GSM,"WITH GSM \r\n");
delay_ms(4000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(1000); 
}

send_smsemergency()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"ATE0\r\n");
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */
fputc(0x0d,GSM); 
//fprintf(GSM,"AT+CNMI=1,2,0,0\r\n"); 
//fputc(0x0d,GSM); 
//fprintf(GSM,"AT+CSMP=17,167,0,0\r\n"); 
//delay_ms(1000);
//fputc(0x0d,GSM);
delay_ms(1000);

/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9515226006\"");   /////////////////////////////////////////////////
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(2500); 

fprintf(GSM,"EMERGENCY SITUATION, PLEASE HELP\r\n");delay_ms(200); 
//fprintf(GSM,"WITH GSM \r\n");
delay_ms(4000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(1000); 
}


//MAIN PROGRAMMING.....................................................

void main()
 {
 lcd_init();
 
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(ALL_ANALOG);
    
    
    
    
    
    show_projectname();
    send_sms();
//HEALTH CHECK UP................
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
   
   
   while (true)
   {
   ///////////////////////////////////////////////////
    ch= fgetc(PC);
   if(ch == 't') //forward    R
   {
   output_high(pin_d2);
   output_low(pin_d3);
   
   
    printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"TEMPERATURE ALERT");
              lcd_gotoxy(1,2);
              printf(lcd_putc,"  SENDING SMS  ");
              delay_ms(1500);
         send_smstemp();
         ch = '\0';
           printf(lcd_putc,"\f");
              
   }
   
   else if (ch == 'g')
   {
    output_high(pin_d2);
   output_low(pin_d3);
   
   
   printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc,"   GAS ALERT   ");
              lcd_gotoxy(1,2);
              printf(lcd_putc,"  SENDING SMS  ");
              delay_ms(1500);  
         send_smsgas();
         ch = '\0';
           printf(lcd_putc,"\f");
              
   }
    else if (ch == 'h')
   {
    output_high(pin_d2);
   output_low(pin_d3);
   
   
   printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
              printf(lcd_putc," HUMIDITY ALERT ");
              lcd_gotoxy(1,2);
              printf(lcd_putc,"  SENDING SMS  ");
              delay_ms(1500);  
         send_smshum();
         ch = '\0';
           printf(lcd_putc,"\f");
              
   }
      else if (ch == 'w')
   {
    output_high(pin_d2);
   output_low(pin_d3);
   
   
   printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
               printf(lcd_putc,"WATER LEVEL ALERT");;
              lcd_gotoxy(1,2);
              printf(lcd_putc,"  SENDING SMS  ");
              delay_ms(1500);  
         send_smswat();
         ch = '\0';
           printf(lcd_putc,"\f");
              
   }
      else if (ch == 'b')
   {
    output_high(pin_d2);
   output_low(pin_d3);
   
   
   printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
               printf(lcd_putc,"EMERGENCY ALERT");;
              lcd_gotoxy(1,2);
              printf(lcd_putc,"  SENDING SMS  ");
              delay_ms(1500);  
         send_smsemergency();
           printf(lcd_putc,"\f");
        ch = '\0';      
   }
   
      else if (ch == 'e')
   {
    output_high(pin_d2);
   output_low(pin_d3);
   
   
   printf(lcd_putc,"\f");
              lcd_gotoxy(0,1);
               printf(lcd_putc,"SYSTEM IS NORMAL");;
              lcd_gotoxy(1,2);
              printf(lcd_putc,"*******************");
              delay_ms(1500);  
        ch = '\0';
           printf(lcd_putc,"\f");
              
   }
   
   /////////////////////////////////////////////////////
   
   
    
     
   }  //WHILE
 }  //MAIN
    
    



