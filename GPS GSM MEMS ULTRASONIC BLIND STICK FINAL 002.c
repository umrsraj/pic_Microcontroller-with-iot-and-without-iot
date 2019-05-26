/*****************************************************************************
TITLE:
 GPS,GSM, MEMS AND IR SENSOR BASED BLIND STICK
 MEMS=A0,A1,
 GSM=B1
 GPS = B0,
 D2=GREEN LED,
 D3= RED LED,
 IR OBSTACLE SENSOR = E2
 D7= BUZZER,
 APR9600 VOICE MODULE =C0,C1,C2. 
****************************************************************************/

//#include <16F877A.h>
#include <18F452.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#fuses  HS,NOWDT,PROTECT,brownout,put
#use  delay  (clock=20M)
#use rs232  (baud = 9600, xmit=PIN_D6,stream=GSM)
#use  rs232  (baud = 9600, rcv=PIN_D7,stream=GPS)
#include <flex_lcd.c>

byte ch = 0;
int count = 0;
byte data[96]; //For SMS storage
//byte err[] = { "ERR" };
//byte unlock_passwd[] = {"1234"};
//byte mynum[] = { "9160231664" }; //Emergency Call Number Cuddapah
char valid_data[] = { ",A," };
char invalid_data[] = { ",V," };



///////////////////////////////////////////
byte num[12];
char lat[12];
char lngtd[12];
//char speed[12];
char tdata[12];
int i=0;
int flag1=0;

#INT_EXT
void ext_isr(void)
{
flag1=1;
   
}


//GPS FUCTION........
void get_GPS_data()
{
   byte ch;
   count = 0;
   data[count] = 0;
   while(1) //                        $GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A
   {
      while(fgetc(GPS) != '$');         //$GPRMC,120029.000,V,0000.0000,N,00000.0000,E,000.0,000.0,280606,,,N*74
      if(fgetc(GPS) == 'G')
        if(fgetc(GPS) == 'P')           //$GPRMC,022042.000,V,1720.1007,N,07832.9310,E,004.3,227.6,190815,,,N*75
          if(fgetc(GPS) == 'R')
            if(fgetc(GPS) == 'M')
               if(fgetc(GPS) == 'C')
               {
                  while(fgetc(GPS) != ',');
                  while(fgetc(GPS) != ',');
                  ch = fgetc(GPS);
                  while(ch != '*')
                  {
                     data[count] = ch;
                     count++;
                     ch = fgetc(GPS);
                  }               
                  data[count] = 0;   //LAST CHARACTER OF STRING ==0
                  break;
               }
  
  }
  
}  //GPS FUN CLOSE



void get_gps_field(byte buf[],int field)
{   
   int i = 0;
   int j = 0;
   int count = 0;
   
   while(buf[i])
   {
      if(buf[i] == ',')
         count++;
      if(count == field)  //1
         break;
      i++;
   }
   i++;
   while(buf[i] != ',')
   {
      tdata[j] = buf[i];
      i++;
      j++;
   }
   tdata[j] = 0;   //STRING ==0
}



void convert_to_GE()
{
   long dd;
   
   i=1;
   get_gps_field(data,1);
   dd = atof(tdata)/100;
   sprintf(lat,"%.6f",dd+(atof(tdata)-(float)(dd*100))/60);
   
   get_gps_field(data,3);
   dd = atof(tdata)/100;
   sprintf(lngtd,"%.6f",dd+(atof(tdata)-(float)(dd*100))/60);
}


/////////////////message sending///////////////////////////////////////////////////////////////

//3RD
void send_sms4()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1500);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9427698689\"");
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1500); 

fprintf(GSM,"BLIND STICK KIT ON............... ");
delay_ms(1500); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
}



void send_sms1()
{
fprintf(GSM,"AT\r\n");    
DELAY_MS(1500);                /* checks are they communicating */
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1500);                                         /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9427698689\""); /* sents the following text to this number */ 
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1500); 
fprintf(GSM,"I AM IN TROUBLE at lat=%5.6f lng=%5.6f \r\n",atof(lat),atof(lngtd)); /* the text that will actually be sent */ 
delay_ms(1500); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
} 


void send_sms2()
{
fprintf(GSM,"AT\r\n");    
DELAY_MS(1500);                /* checks are they communicating */
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1500);                                         /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9427037603\""); /* sents the following text to this number */ 
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1500); 
fprintf(GSM,"I AM IN TROUBLE at lat=%5.6f lng=%5.6f \r\n",atof(lat),atof(lngtd)); /* the text that will actually be sent */ 
delay_ms(1500); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
} 


void send_sms3()
{
fprintf(GSM,"AT\r\n");    
DELAY_MS(1500);                /* checks are they communicating */
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1500);                                         /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9727828258\""); /* sents the following text to this number */ 
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1500); 
fprintf(GSM,"I AM IN TROUBLE at lat=%5.6f lng=%5.6f \r\n",atof(lat),atof(lngtd)); /* the text that will actually be sent */ 
delay_ms(1500); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
} 


////////////////////////////////////////////////////////////////////////////////

//MAIN PROGRAMMING-------------------------------------------------------------
void main()
{
     
   lcd_init(); 
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG ); 
   
   float adc_value1,adc_value2;
   int ir;
   int wl;
   
      // ext_int_edge(H_TO_L);       // Interrupt on falling edge of RB0/INT pin
  ext_int_edge(L_TO_H);       // Interrupt on falling edge of RB0/INT pin
  clear_interrupt(INT_EXT);   // Clear RB0/INT external interrupt flag bit
  enable_interrupts(INT_EXT); // Enable RB0/INT external interrupt
  enable_interrupts(GLOBAL);  // Enable all unmasked interrupt
  
//DISPLAY INITIAL MESSAGE
          lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"GPS & GSM BASED  ");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"SMART BLIND STICK ");         
         delay_ms(2000); 
                  
           //APR 9600 VOICE MODULE
   output_high(PIN_C0);  
   output_high(PIN_C1);  
   output_high(PIN_C2);  
   output_high(PIN_C3); 
   output_high(PIN_D0);  
   output_high(PIN_D1);  
  
   
          output_low(PIN_C0);
         delay_ms(200);
         output_high(PIN_C0);
         
         //HEALTH CHECK UP..........................................
 //  output_high(PIN_c4);  //BUSSER ON
   output_high(PIN_D2);  //GREEN LED ON
   output_high(PIN_D3);  //RED LED ON
   delay_ms(500);
  // output_low(PIN_c4);
   output_low(PIN_D2);
   output_low(PIN_D3);
   delay_ms(500);
 //  output_high(PIN_c4);  //BUSSER ON
   output_high(PIN_D2);  //GREEN LED ON
   output_high(PIN_D3);  //RED LED ON
   delay_ms(500);
  // output_low(PIN_c4);
   output_low(PIN_D2);
   output_low(PIN_D3);
   delay_ms(500);
        send_sms4();
        delay_ms(3000);

lcd_putc('\f');
        
//CONTINEOUS LOOP...........................................
  while(1)
  {
      //READ MEMS ADC VALUES...............................
      set_adc_channel(0);                           
     delay_ms(1);
      adc_value1=read_adc(); 


     set_adc_channel(1);                           
     delay_ms(1);
     adc_value2=read_adc(); 
   
      set_adc_channel(3);                           
     delay_ms(1);
      wl=read_adc(); 
   
     set_adc_channel(7);                           
     delay_ms(1);
     ir=read_adc(); 
      
      //lcd_gotoxy(1,1);
      //printf(lcd_putc,"x:%f ",adc_value1);
     // printf(lcd_putc,"y:%f ", adc_value2);
     //delay_ms(500);
      
          lcd_putc('\f');
        lcd_gotoxy(0,1);
         printf(lcd_putc,"SMRT BLIND STICK ");
         lcd_gotoxy(1,2);
         printf(lcd_putc,">----------->>>");
         delay_ms(700);  

       
 //IF ACCIDENT OCCUR /////////////////////////////////////////////////////MEMS VAUES AT FOUR DIRECTIONS/////////////////////////////
//if(((adc_value2<68)||(adc_value2>95))||((adc_value1<68)||(adc_value1>95)))   
//if((adc_value2>100)||(adc_value2<60))
 if((adc_value2>120)||(adc_value2<90))
 {
     output_high(pin_d3);   //  RED LED ON
     output_low(pin_d2);   // GREEN LED ON
     output_high(pin_c4);   //BUZZER ON        
     
     //APR VOICE ALERT
         output_low(PIN_C1);
         delay_ms(300);
         output_high(PIN_C1);
     output_low(pin_C4);   //BUZZER OFF        
         
     printf(lcd_putc,"\f");
     lcd_gotoxy(2,1);
     printf(lcd_putc," FALLING ALERT");
     lcd_gotoxy(1,2);
     printf(lcd_putc," **PLS SAVE ME**");
    delay_ms(1500);
     
   get_GPS_data();
     convert_to_GE();
  //  lcd_putc('\f');
if(strstr(data,valid_data))
   {
        // output_low(PIN_D2);
         //output_high(PIN_D3);
         lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"lat:%5.6f",atof(lat));
         lcd_gotoxy(1,2);
         printf(lcd_putc,"lng:%5.6f",atof(lngtd));
        // delay_ms(1000);
      }     
      if(strstr(data,invalid_data))
      {
        lcd_putc('\f');
        lcd_gotoxy(1,1);
         printf(lcd_putc,"lat:17.2827");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"lng:78.5531");
         delay_ms(1500);  
      }    
     lcd_putc('\f');
        lcd_gotoxy(1,1);
         printf(lcd_putc,"lat:17.2827");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"lng:78.5531");
         delay_ms(700);
         
         send_sms1();  //1ST PERSON SMS...............................
           printf(lcd_putc,"\f");
     lcd_gotoxy(2,1);
     printf(lcd_putc," SMS SENDING....");
     lcd_gotoxy(1,2);
     printf(lcd_putc," **************");
    delay_ms(3500);
    
 output_low(pin_c4);   //BUZZER ON  
  //READ GPS VALUES.................   .
   
  
    send_sms2();  //1ST PERSON SMS...............................    
      delay_ms(4000); //delay_ms(2000);
        
      send_sms3();  //1ST PERSON SMS...............................
       printf(lcd_putc,"\f");
     lcd_gotoxy(4,1);
     printf(lcd_putc," SENT SMS....");
     lcd_gotoxy(1,2);
     printf(lcd_putc," **************");
        delay_ms(4000);
}

   
              

//OBSTACLE AERT
//IF ACCIDENT OCCUR /////////////////////////////////////////////////////MEMS VAUES AT FOUR DIRECTIONS/////////////////////////////

if(ir<70)
  {
     output_high(pin_d3);   //  RED LED ON
     output_low(pin_d2);   // GREEN LED ON
     output_high(pin_c4);   //BUZZER ON        
     
     //APR VOICE ALERT
         output_low(PIN_C2);
         delay_ms(100);
         output_high(PIN_C2);
         
 output_low(pin_c4);   //BUZZER Off       
             
     printf(lcd_putc,"\f");
     lcd_gotoxy(1,1);
     printf(lcd_putc,"MANHOLE/STEPS");
     lcd_gotoxy(0,2);
     printf(lcd_putc,"DETECTED. PLS STOP**");
      delay_ms(1000);
  }

   
//WAER LEVEL DETECT
//IF water detect /////////////////////////////////////////////////////MEMS VAUES AT FOUR DIRECTIONS/////////////////////////////
 //if(input(pin_E2))
if(wl>30)
  {
     output_high(pin_d3);   //  RED LED ON
     output_low(pin_d2);   // GREEN LED ON
     output_high(pin_c4);   //BUZZER ON        
     
     //APR VOICE ALERT
         output_low(PIN_C3);
         delay_ms(100);
         output_high(PIN_C3);
         
    output_low(pin_c4);   //BUZZER Off       
             
     printf(lcd_putc,"\f");
     lcd_gotoxy(1,1);
     printf(lcd_putc," WATER DETECTED");
     lcd_gotoxy(1,2);
     printf(lcd_putc," **PLS STOP**");
       
      delay_ms(1000);
  }


//OBSTACLE AERT
//IF ACCIDENT OCCUR /////////////////////////////////////////////////////MEMS VAUES AT FOUR DIRECTIONS/////////////////////////////

 //if(input(pin_E2))
if(flag1==1)
  {
  flag1=0;
     output_high(pin_d3);   //  RED LED ON
     output_low(pin_d2);   // GREEN LED ON
     output_high(pin_c4);   //BUZZER ON        
     
  //APR VOICE ALERT
      output_low(PIN_d0);
      delay_ms(100);
     output_high(PIN_d0);
     output_low(pin_c4);   //BUZZER Off       
     
     printf(lcd_putc,"\f");
     lcd_gotoxy(1,1);
     printf(lcd_putc,"OBSTACLE ALERT");
     lcd_gotoxy(1,2);
     printf(lcd_putc," **PLS STOP**");
     delay_ms(1000);
  }

        output_low(pin_C4);  //BUZZER ON
        output_high(pin_D2);  //GREEN LED ON
        output_low(pin_D3);  //RED LED OFF
        delay_ms(1000);
           //APR 9600 VOICE MODULE
   output_high(PIN_C0);  
   output_high(PIN_C1);  
   output_high(PIN_C2);  
   output_high(PIN_C3); 
   output_high(PIN_D0);  
   output_high(PIN_D1); 
     

  }// WHILE......................................................................  
  
}//MAIN






