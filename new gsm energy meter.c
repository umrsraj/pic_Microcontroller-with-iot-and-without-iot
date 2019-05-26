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
#use rs232 (baud = 9600, xmit=PIN_c0, rcv=PIN_c1,stream=PC)
#use rs232(baud=9600, xmit=PIN_b0, rcv=PIN_b1,stream=GSM)  //   INTERRUPT CODDE
#include <flex_lcd.c>  //LCD HEADER
char notice_data[90];
unsigned int l=0;
char ch;
 unsigned int16 cnt=0,ct=0,bal=0;

///////////////////////////////////////////
int i=0;
//units-------
//char units1[3] = "50";
//char units2[3] = "70";
  
  
void show_projectname()
{
      lcd_putc('\f');
      lcd_gotoxy(3,1);
      printf(lcd_putc," PREPAID   ");
      lcd_gotoxy(2,2);
      printf(lcd_putc,"ENERGY METER ");
      delay_ms(2000);
      
       lcd_putc('\f');
      lcd_gotoxy(3,1);
      printf(lcd_putc,"USING GSM   ");
      lcd_gotoxy(0,2);
      printf(lcd_putc,"---------------");
      delay_ms(2000);
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
fprintf(GSM,"AT+CMGS=\"7842282580\"");   /////////////////////////////////////////////////
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(2500); 

fprintf(GSM,"WELCOME!! PREPAID ENERGY METER \r\n");delay_ms(200); 
fprintf(GSM,"WITH GSM \r\n");
delay_ms(4000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(1000); 
}

//AFTER RECHARGE SMS SENT---------------
void send_sms1()
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
fprintf(GSM,"AT+CMGS=\"7842282580\"");   /////////////////////////////////////////////////
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(2500); 

fprintf(GSM,"UR METER RECHAGED. UNITS=%lu\r\n",bal);delay_ms(200); 
fprintf(GSM,"WITH GSM \r\n");
delay_ms(4000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(1000); 
}

//low balance---------------
void send_sms2()
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
fprintf(GSM,"AT+CMGS=\"7842282580\"");   /////////////////////////////////////////////////
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(2500); 

fprintf(GSM,"UR BALANCE IS LOW. R_UNITS=%lu\r\n",bal);delay_ms(200); 
fprintf(GSM,"WITH GSM \r\n");
delay_ms(4000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(1000); 
}

//BALANCE ZERO = LOAD OFF---------------
void send_sms3()
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
fprintf(GSM,"AT+CMGS=\"7842282580\"");   /////////////////////////////////////////////////
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(2500); 

fprintf(GSM,"UR BALANCE IS ZERO.LOAD OFF\r\n");delay_ms(200); 
fprintf(GSM,"WITH GSM \r\n");
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
      output_high(pin_c4);  //GREEN LED ON
      output_high(pin_c5);  //RED LED ON
      delay_ms(500);
      output_low(pin_c4);  //GREEN LED OFF
      output_low(pin_c5);  //RED LED OFF
      delay_ms(500);beep();
      output_high(pin_c4);  //GREEN LED ON
      output_high(pin_c5);  //RED LED ON
      delay_ms(500);
      output_low(pin_c4);  //GREEN LED OFF
      output_low(pin_c5);  //RED LED OFF
      delay_ms(500);beep();      
                     //project name on lcd
    delay_ms(3000);
   
   while (true)
   {
    y:
  //1st process------------------------------  
      lcd_putc('\f');
      lcd_gotoxy(0,1);
      printf(lcd_putc,"PLS RECHAR UNITS");
      delay_ms(500);
  
   set_adc_channel(0);
    delay_ms(1);
    ct = read_adc();
    delay_ms(1);
  
  //RECAGE PROCESS---------------------
     do 
     {
     ch= fgetc(GSM);
     }while(ch!='*');
  
     i=0;
     do 
     {
     ch= fgetc(GSM);
     notice_data[i++]=ch;
     }while(ch!='#');
     notice_data[--i]='\0';
     // lcd_putc('\f'); //clear LCD display
    // lcd_gotoxy(1,2); // go to row 2 and column 1
    // printf(lcd_putc,notice_data); //display college name
     fprintf(PC,"REC UNITS=%s"notice_data);
     delay_ms(1500);
     
 l=atoi(notice_data);   //strin
  
     lcd_putc('\f'); //clear LCD display
     lcd_gotoxy(0,1); // go to row 2 and column 1
     printf(lcd_putc,"E_MTR RECHAGED "); //display college name
     lcd_gotoxy(0,2); // go to row 2 and column 1
     printf(lcd_putc,"UNITS= %u",l); //display college name
     send_sms1();delay_ms(500);
    
    bal=l;
  
             //comparison
             while(bal>=1)    //if card have minimum balance
            {
            output_high(PIN_D7);
             output_high(PIN_C4); //LED indicator ON
             output_high(PIN_C7);           
                set_adc_channel(0);
                delay_ms(1);
                ct = read_adc();
                delay_ms(1);
                
                
                if(ct<40)
                {
                    output_high(pin_c4);  //g on
                    cnt++;
                    lcd_putc('\f');         //Clear LCD
                  lcd_gotoxy(0,1);
                  printf(lcd_putc,"UNITS :%lu UNITS" ,cnt);
                 delay_ms(500);
                output_low(pin_c4);  //g off
                
                // bal=bal-cnt;
                bal=bal-1;
                 lcd_gotoxy(0,2);
                 printf(lcd_putc,"RE UNITS =%Lu",bal);
                 delay_ms(1500);
                  }
            
            
             
                   //alert sms sending...
                   
                     if(bal==5)
                     {
                     
                       lcd_putc('\f');
                       lcd_gotoxy(1,1);
                       printf(lcd_putc,"YOUR BAL LOW");
                            lcd_gotoxy(1,2);
                       printf(lcd_putc,"PLEASE RECHARGE...");beep();beep();
                          send_sms2();delay_ms(500);
                      //continue;
                      cnt++;
                     bal=bal-1;
                     }
                           
            }//  balance --------------------------------------------------
               if(bal==0)
               { 
               output_low(PIN_D7);
               lcd_putc('\f');
                 lcd_gotoxy(3,1);
                 printf(lcd_putc,"BALANCE ZERO ");
                 lcd_gotoxy(1,2);
                 printf(lcd_putc,"  LOAD OFF ");
                output_high(pin_C5);  //RED LED ON
                output_low(pin_C4);  //LED OFF
                output_low(pin_C7);  //LOAD OFF
                beep();    
                send_sms3();delay_ms(500);
               goto y;
               
               }//balance less


/*
/compare message 
  if(notice_data[0]=='5' && notice_data[1]=='0')
  {
     lcd_putc('\f'); //clear LCD display
     lcd_gotoxy(1,1); // go to row 2 and column 1
     printf(lcd_putc,"recharged un=50"); //display college name
     lcd_gotoxy(1,2);
     printf(lcd_putc,"units =%u",l);
     delay_ms(1500);
  
  }
   

  //compare message 
  //if( notice_data=="100")
  if(!strcmp(notice_data,units2))
  {
     lcd_putc('\f'); //clear LCD display
     lcd_gotoxy(1,1); // go to row 2 and column 1
     printf(lcd_putc,"recharged un=70"); //display college name
     lcd_gotoxy(1,2);
     //printf(lcd_putc,notice_data);
      printf(lcd_putc,"units =%u",l);
     delay_ms(1500);
  
  }
  
*/
     
   }  //WHILE
 }  //MAIN
    
    



