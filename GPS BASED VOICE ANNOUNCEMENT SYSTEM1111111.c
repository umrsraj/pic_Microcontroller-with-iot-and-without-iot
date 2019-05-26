/*****************************************************************************
TITLE:
 GPS BASED VOICE ANNOUNCEMENT FOR THE BLIND 
 GPS=A0,
 GSM=B0,B1,
 D2=GREEN LED,
 D3= RED LED,
D1=BUZZER,
****************************************************************************/
#include <16F877A.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#fuses      HS,NOWDT,PROTECT,brownout,put
#use        delay  (clock=20M)
#use        rs232  (baud = 9600, xmit=PIN_A1,rcv=PIN_A0,stream=GPS)
#include <flex_lcd.c>

byte ch = 0;
int count = 0;
byte data[96]; //For SMS storage
//byte err[] = { "ERR" };
//byte unlock_passwd[] = {"1234"};
//byte mynum[] = { "9160231664" }; //Emergency Call Number Cuddapah
char valid_data[] = { ",A," };
char invalid_data[] = { ",V," };


//comparision PLACE alert values..........................

char boarder1_data[] = { ".28366" };    //AURORA COLLEGE GATE ENTRANCE(WELCOME TO AURORA COLLEGE)
char boarder2_data[] = { ".70857" };

//char boarder1_data[] = { ".36951" };    //AURORA COLLEGE GATE ENTRANCE(WELCOME TO AURORA COLLEGE)
//char boarder2_data[] = { ".52868" };


char boarder3_data[] = { ".2838" };    //AURORA COLLEGE OFFICE
char boarder4_data[] = { ".7089" };

//char boarder3_data[] = { ".36955" };    //AURORA COLLEGE GATE ENTRANCE(WELCOME TO AURORA COLLEGE)
//char boarder4_data[] = { ".52871" };



char boarder5_data[] = { ".2969" };    //AURORA COLLEGE HOD ROOM 
char boarder6_data[] = { ".7090" };


char boarder7_data[] = { ".2835" };    //AURORA COLLEGE ECE DEPT
char boarder8_data[] = { ".7084" };

///////////////////////////////////////////



///////////////////////////////////////////
byte num[12];
char lat[12];
char lngtd[12];
//char speed[12];
char tdata[12];
int i=0;


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


//MAIN PROGRAMMING-------------------------------------------------------------
void main()
{
   lcd_init();
    
   //HEALTH CHECK UP..........................................
   output_high(PIN_d2);  //BUSSER ON
   output_high(PIN_d3);  //GREEN LED ON
   output_high(PIN_c4);  //RED LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(500);
   output_low(PIN_d2);
   output_low(PIN_d3);
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(500);
   output_high(PIN_d2);  //BUSSER ON
   output_high(PIN_d3);  //GREEN LED ON
   output_high(PIN_c4);  //RED LED ON
   output_high(PIN_c5);  //RED LED ON
   delay_ms(500);
   output_low(PIN_d2);
   output_low(PIN_d3);
   output_low(PIN_c4);
   output_low(PIN_c5);
   delay_ms(500);
output_high(PIN_c0);output_high(PIN_c1);output_high(PIN_c2);output_high(PIN_c3);output_high(PIN_d0);output_high(PIN_d1);
//DISPLAY INITIAL MESSAGE
          lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"BLIND PERSON    ");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"NAVIGATION SYSTEM ");         
         delay_ms(2000); 
   output_low(PIN_c0);  //RED LED ON
   delay_ms(4000);
   output_high(PIN_c0);
   
       lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"USING GPS & ");
         lcd_gotoxy(0,2);
         printf(lcd_putc,"VOICE RECOGNISATION ");         
               
        delay_ms(2000);

lcd_putc('\f');
        
//CONTINEOUS LOOP...........................................
  while(1)
  {
 //output_high(pin_d2);  //GREEN LED OFF
     get_GPS_data();
     convert_to_GE();

//**********************current GPS VALUE****************************************


 //1ST VOICE
//WELCOME TO AUROTA COLLEGE
if((strstr(data,boarder1_data)!=0)||(strstr(data,boarder2_data)!=0))       //hod room crosssing

{    output_high(pin_d2);   //LED ON
     output_low(PIN_c1);  //RED LED ON
       printf(lcd_putc,"\f");
     lcd_gotoxy(2,1);
     printf(lcd_putc," CLASSROOM ");
     lcd_gotoxy(3,2);
     printf(lcd_putc,"MATCHED");
     // send_sms1();
      delay_ms(2000);
      output_high(PIN_c1); 
    output_low(pin_d2);
 
}


//2ND

else if((strstr(data,boarder3_data)!=0)||(strstr(data,boarder4_data)!=0))       //hod room crosssing
{ 
    output_high(pin_d3);   //LED ON
        output_low(pin_c2); 
    printf(lcd_putc,"\f");
     lcd_gotoxy(2,1);
     printf(lcd_putc," SEMINOR HALL");
     lcd_gotoxy(3,2);
     printf(lcd_putc," MATCHED ");
    //  send_sms2();
      delay_ms(2000);
      output_low(pin_d3);
      output_high(pin_c2); 
  

}


//3RD 
else if((strstr(data,boarder5_data)!=0)||(strstr(data,boarder6_data)!=0))       //hod room crosssing

{
  output_high(pin_c4);
  output_low(pin_c3);
  //LED ON
     printf(lcd_putc,"\f");
     lcd_gotoxy(2,1);
     printf(lcd_putc," SEMINOR HALL");
     lcd_gotoxy(3,2);
     printf(lcd_putc," MATCHED ");
     // send_sms3();
      delay_ms(2000);
      output_low(pin_c4);
          output_high(pin_c3); 
        

}

 //1ST VOICE
//WELCOME TO AUROTA COLLEGE
else if((strstr(data,boarder7_data)!=0)||(strstr(data,boarder8_data)!=0))       //hod room crosssing

{    output_high(pin_d2);   //LED ON
     output_low(PIN_c1);  //RED LED ON
       printf(lcd_putc,"\f");
     lcd_gotoxy(2,1);
     printf(lcd_putc," CLASSROOM ");
     lcd_gotoxy(3,2);
     printf(lcd_putc,"MATCHED");
     // send_sms1();
      delay_ms(2000);
      output_high(PIN_c1); 
    output_low(pin_d2);
 
}



//else
{      
        output_low(pin_d2);  //GREEN LED OFF
        output_low(pin_c4);  //RED LED ON
        delay_ms(1000);
  
          lcd_putc('\f');
//if(strstr(data,valid_data))
     // {
        // output_low(PIN_D2);
         //output_high(PIN_D3);
         lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"lat:%5.6f",atof(lat));
         lcd_gotoxy(1,2);
         printf(lcd_putc,"lng:%5.6f",atof(lngtd));
        // delay_ms(1000);
    //  }     
      if(strstr(data,invalid_data))
      {
        // lcd_putc('\f');
         lcd_gotoxy(1,1);
         printf(lcd_putc,"lat:0000000");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"lng:0000000");
         delay_ms(500);  
      }        
       
}
    
   
  
  }
// WHILE......................................................................  
  
}//MAIN





