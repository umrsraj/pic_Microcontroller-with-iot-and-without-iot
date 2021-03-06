/******************************************************************************

TITLE: TRANSFORMER DETECTION OF TRASNSORMER WITH GSM AND MULTIPL FAULTS
A0= TEMPERATURE SENSOR,
A1= VOLTAGE SENSOR,
A2= CURRENT TRASFORMER,

C0= FAULT DETECITON
C1=
C2= 

B0= LCD DISPLAY,

 D1= BUZZER,
D7= RELAY AC LOAD
D6= DC COOLING FAN,
D2= GREEN LED.IFSYSTEM IS OK
D3= RED LED FOR ALERT.

*********************************************************************************/
#include <16F877a.h>           //Microcontroller Used
#fuses HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include "flex_lcd.c"
#use rs232(baud=9600, xmit=PIN_B0, rcv=PIN_B1,stream=GSM)


void send_sms1()
{

fprintf(GSM,"AT\r\n");                    /* checks are they communicating */
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9182306443\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM,"WELCOME !! FAULT DETECTION OF TRASNFORMER WITH GSM \r\n");
delay_ms(1000); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 


fprintf(GSM,"AT\r\n");                    /* checks are they communicating */
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
/*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"9701466795\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(2500); 
fprintf(GSM,"WELCOME !! FAULT DETECTION OF TRASNFORMER WITH GSM \r\n");
delay_ms(2500); 
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 

}

//OVER TEMPERATURE ALERT
//2nd number
void send_sms2()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"+919182306443\"");
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"OVER TEMP ALERT= COOLER ON \r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 

fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"+919701466795\"");
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"OVER TEMP ALERT= COOLER ON \r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 
}



//VOLTAGE ALERT
//3RD MESSAGE
void send_sms3()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"+919182306443\"");
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"VOLTAGE ALERT*****PLS CHECK***\r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 

fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"+919701466795\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM,"VOLTAGE ALERT*****PLS CHECK***\r\n");
delay_ms(1000);
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 
}

//4TH MESSAGE OVER CURRENT
void send_sms4()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"+919182306443\"");
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"OVER CURRENT*****PLS CHECK***\r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 

fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"+919701466795\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM,"OVER CURRENT*****PLS CHECK***\r\n");
delay_ms(1000);
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 
}



//5TH MESSAGE LINE TO LINE ALERT
void send_sms5()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"+919182306443\"");
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"LINE TO LINE ALERT*****PLS CHECK***\r\n");
delay_ms(1000); 

fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 

fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"+919701466795\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM,"LINE TO LINE ALERT*****PLS CHECK***\r\n");
delay_ms(2500);
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 
}


//6TH MESSAGE LINE TO GND ALERT
void send_sms6()
{
fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"+919182306443\"");
 fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 

fprintf(GSM,"LINE OT GND ALERT*****PLS CHECK***\r\n");
delay_ms(1000);
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 

fprintf(GSM,"AT\r\n");                    /* checks are they communicating */ 
fprintf(GSM,"AT+CMGF=1\r\n");             /* sends an at command reay to send */ 
fputc(0x0d,GSM); 
delay_ms(1000);
                                          /*sends a carriage return */
fprintf(GSM,"AT+CMGS=\"+919701466795\"");
fprintf(GSM,"\r\n");                      /* cariage */ 
fputc(0x0d,GSM); 
delay_ms(1000); 
fprintf(GSM,"LINE OT GND ALERT*****PLS CHECK***\r\n");
delay_ms(1000);
fprintf(GSM,"\r\n"); 
fputc(0x1A,GSM);                          /* sends CTRL Z */ 
delay_ms(4000); 
}



void beep()
{
output_high(pin_d1);
delay_ms(1000);
output_low(pin_d1);
}

void main()
{
//int temp;
   float temp1,temp2;
  unsigned int vol,cur;
   
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports( ALL_ANALOG );  
   
      lcd_init();
   printf(lcd_putc,"\f");
   lcd_gotoxy(1,1);
   printf(lcd_putc,"FAULT DETECTION &");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"PROTECTION OF TRSN");
   delay_ms(2500);

   printf(lcd_putc,"\f");
   lcd_gotoxy(4,1);
   printf(lcd_putc,"WITH GSM ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"------------------");
   delay_ms(2500);  //health check
  send_sms1();
   output_high(pin_d1);       // BUZZER ON
   output_high(pin_d2);       // GREEN LED ON
   output_high(pin_d3);       // RED LED ON
   delay_ms(500);
   output_low(pin_d1);       // BUZZER OFF
   output_low(pin_d2);
   output_low(pin_d3);
   delay_ms(500);
   output_high(pin_d1);       // BUZZER ON
   output_high(pin_d2);       // GREEN LED ON
   output_high(pin_d3);       // RED LED ON
   delay_ms(500);
   output_low(pin_d1);       // BUZZER OFF
   output_low(pin_d2);
   output_low(pin_d3);
   delay_ms(500);
   
   printf(lcd_putc,"\f");
 
  //output_high(pin_c7);
 
   while(1)
   {
   
   //TEMPEARTURE READ   
      set_adc_channel(0);    //A0 PIN 2 PIN                        
      delay_ms(1);
      temp1=read_adc();     
     delay_ms(1);
      temp2 = (temp1 * 100)/256;
      temp2 = temp2 * 5;
     
     set_adc_channel(1);    //A0 PIN 2 PIN                        
      delay_ms(1);
      vol=read_adc();     
     
     set_adc_channel(2);    //A0 PIN 2 PIN                        
      delay_ms(1);
      cur=read_adc();     
  /*   
      printf(lcd_putc,"\f");
      lcd_gotoxy(0,1);
      printf(lcd_putc,"TEM=%2.0g%cC",temp2,0xDF);
      lcd_gotoxy(9,1);
      printf(lcd_putc,",VOL=%u V",vol);
      lcd_gotoxy(3,2);
      printf(lcd_putc,"CUR =%u mA",cur);
     delay_ms(1000);
     */
     
    
// 1st over temp alert-------     
  
      if(temp2>45)  //IF TEMPERATURE CROSSES
      {
      printf(lcd_putc,"\f");
      lcd_gotoxy(0,1);
      printf(lcd_putc,"TRANS OVER HEATED... ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"TRA TEMP=%2.0g%cC",temp2,0xDF);
      delay_ms(1500);
       output_low(pin_D7); 
      output_high(pin_D6); //cooler on
      beep(); 
           output_low(pin_D2); //GREEN OFF
      output_high(pin_D3); //RED LED ON
      output_high(pin_D1); //BUZZER ON
        send_sms2();
      delay_ms(700); 
      }
      
      if(temp2<40)  //IF TEMPERATURE CROSSES
      {
       output_low(pin_D6); //GREEN OFF
      delay_ms(700); 
      }
      
      
   //2ND OVER VOLTAGE ALERT
    if((vol>245)||(vol<180))  //IF TEMPERATURE CROSSES
      {
      printf(lcd_putc,"\f");
      lcd_gotoxy(0,1);
      printf(lcd_putc," VOLTAG ALERT... ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"VOLTAGE =%u V",vol);
      delay_ms(1500);
      output_low(pin_D7); 
      beep();
      output_low(pin_D2); //GREEN OFF
      output_high(pin_D3); //RED LED ON
      output_high(pin_D1); //BUZZER ON
        send_sms3();
      delay_ms(700); 
      }
      
   
   
   //3rD OVER CURRENT ALERT
    if(cur>35)  //IF T
      {
      printf(lcd_putc,"\f");
      lcd_gotoxy(0,1);
      printf(lcd_putc,"OVER CURRENT ALERT... ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"CURENT =%u mA",cur);
      delay_ms(1500);
      
      output_low(pin_D7);
      beep();
      output_low(pin_D2); //GREEN OFF
      output_high(pin_D3); //RED LED ON
      output_high(pin_D1); //BUZZER ON
        send_sms4();
      delay_ms(700); 
      }
      
    //4th line to line  ALERT
    if(!input(pin_c0))  //IF T
      {
      printf(lcd_putc,"\f");
      lcd_gotoxy(0,1);
      printf(lcd_putc,"LINE TO LINE ALERT.. ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"PLS CECK*********");
      delay_ms(1500);
      
      output_low(pin_D7);
      beep();
      output_low(pin_D2); //GREEN OFF
      output_high(pin_D3); //RED LED ON
      output_high(pin_D1); //BUZZER ON
        send_sms5();
      delay_ms(700); 
      }   
      
    
    //5th line to line  ALERT
    if(!input(pin_c1))  //IF T
      {
      printf(lcd_putc,"\f");
      lcd_gotoxy(0,1);
      printf(lcd_putc,"LINE TO GND ALERT.. ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"PLS CECK*********");
      delay_ms(1500);
      
      output_low(pin_D7);
      beep();
      output_low(pin_D2); //GREEN OFF
      output_high(pin_D3); //RED LED ON
      output_high(pin_D1); //BUZZER ON
        send_sms6();
      delay_ms(700); 
      }     
      
      
      
  //NORMAL CONDIDTION    
      if((temp2<40)&&((vol>180)&&(vol<245))&&(cur<35))
      {

      printf(lcd_putc,"\f");
      lcd_gotoxy(0,1);
      printf(lcd_putc,"TEM=%2.0g%cC",temp2,0xDF);
      lcd_gotoxy(9,1);
      printf(lcd_putc,",VOL=%u V",vol);
      lcd_gotoxy(3,2);
      printf(lcd_putc,"CUR =%u mA",cur);
          
      output_high(pin_d7); //RELAY OFF
      output_high(pin_D2); //GREEN LED ON
      output_LOW(pin_D3); //RED LED OFF
      output_LOW(pin_D1); //BUZZER OFF
      output_LOW(pin_D6); //RED LED OFF
      
      delay_ms(700); 
      }
     
      }//WHILE CLOSE
                              
      }

    






