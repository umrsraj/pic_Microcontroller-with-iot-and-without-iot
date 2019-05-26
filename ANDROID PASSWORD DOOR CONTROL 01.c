/*///////////////////////////////////////////////////////////////////////////
TITLE: ANDROID BLUTOOTH BASED HOME AUTOMATION WITH BLUE CONTROL APP 28 PIN

MICROCONTROLLER NAME:PIC16F73
LCD= B PORT (B2 TO B7),
BLUTOOTH = A0,A1,
4 RELAYS = D7,D6,D5,D4
4 LED'S= D2,D3,C4,C5


////////////////////////////////////////////////////////////////////////////*/
#include <16F73.h>
#fuses      HS,NOWDT,PROTECT,brownout,put
#use        delay  (clock=20000000) //crystall oscillator 
#use        rs232  (baud = 9600, xmit=PIN_B0,rcv=PIN_B1,stream=ZIGBEE)
#include "flex_lcd.c"
#include <string.h>

void beep()
{
output_high(pin_c3);delay_ms(1500);output_low(pin_c3);delay_ms(1000);
}

void main()
{
   char ch; //to get data from Zigbee
int i=0;
unsigned char pwd[5];
char pswd1[5] = "1234";
  char pswd2[5] = "4321";
   lcd_init();
   
   //Microcontroller Health Check
            output_high(PIN_C4); //LED ON
            output_high(PIN_C5); //LED ON
                    delay_ms(500);
            output_low(PIN_C4); //LED OFF
            output_low(PIN_C5); //LED OFF
                      delay_ms(500);   output_high(PIN_C4); //LED ON
            output_high(PIN_C5); //LED ON
                    delay_ms(500);
            output_low(PIN_C4); //LED OFF
            output_low(PIN_C5); //LED OFF
                      delay_ms(500);
            
            
     printf(lcd_putc,"\f");
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Android password ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Bsd Remote-Door ");
      delay_ms(2000);
    
    
     printf(lcd_putc,"\f");
     lcd_gotoxy(3,1);
      printf(lcd_putc,"Access System ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"----------------");
      delay_ms(2000);
      
       fprintf(ZIGBEE,"\r\n ****************************************************\r\n");    delay_ms(700);
       fprintf(ZIGBEE,"\r\n ANDROID PASSWORD BASED REMOTE DOOR ACCESS SYSTEM\r\n",);  delay_ms(700);
       fprintf(ZIGBEE,"\r\n ****************************************************\r\n");    delay_ms(700);delay_ms(1000); 
    
   /*    
     printf(lcd_putc,"\f");
      lcd_gotoxy(3,1);
      printf(lcd_putc,"SYSTEM");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"************ ");
      delay_ms(2000);
   printf(lcd_putc,"\f");   */
     y:
         printf(lcd_putc,"\f");
        lcd_gotoxy(1,1);
       printf(lcd_putc,"Please Enter UR");
    lcd_gotoxy(0,2);
       printf(lcd_putc,"Android Password");
       
       fprintf(ZIGBEE,"\r\n -----------------------------------------------\r\n");    delay_ms(700);
       fprintf(ZIGBEE,"\r\n Please Entere UR 4 Digit Password Pls....\r\n");    delay_ms(700);
       delay_ms(2000);
       
  while(1)
   {
     // ch = getc();
  output_high(pin_C4);delay_ms(300);
     for (i=0; i<4; i++) 
     { 
         pwd[i]=getc();
         printf(lcd_putc,"\f");
         lcd_gotoxy(1,1);
         printf(lcd_putc,"UR PASSWORD IS:",); 
         lcd_gotoxy(i + 1,2);
        //printf(lcd_putc,"%c",pwd[i]); 
        printf(lcd_putc,"%c",'*'); 
       fprintf(ZIGBEE,"\r\nUR PSWD = %c " pwd[i]);  delay_ms(700);
       output_low(pin_c4);  //GREEN LED OFF
     //i = i + 1;
   //  delay_ms(700);
     }     
  
   lcd_putc('\f');
     lcd_gotoxy(1,1);
     printf(lcd_putc,"UR PSWD =%s", pwd);
     lcd_gotoxy(2,2);
     printf(lcd_putc,"Checking........ ");
      fprintf(ZIGBEE,"\r\n -----------------------------------------------------\r\n");    delay_ms(700);
       fprintf(ZIGBEE,"\r\nUR PSWD = %s  Checking..... \r\n",pwd);  delay_ms(700);
     delay_ms(1000); 

  
//if rf data receive.......
if(i==4)
{
i=0;
pwd[4]='\0';

//DOOR OPENING......................................................
if(!strcmp(pwd,pswd1))
{
           
            printf(lcd_putc,"\f");
            lcd_gotoxy(1,1);
            printf(lcd_putc,"Password Matched");
           lcd_gotoxy(1,2);
            printf(lcd_putc,"Door Opening....");
            fprintf(ZIGBEE,"\r\n PASSWORD MATCHED.  DOOR OPENING.....r\n",);  delay_ms(700);
            fprintf(ZIGBEE,"\r\n -----------------------------------------------\r\n");    delay_ms(700);
           delay_ms(2000);
            output_high(pin_c4);output_low(pin_c5);
            output_high(pin_c7);  //relay on
            delay_ms(1000);
            goto y;
            
}


//DOOR CLOSING...................................................
if(!strcmp(pwd,pswd2))
{
            
            printf(lcd_putc,"\f");
            lcd_gotoxy(1,1);
            printf(lcd_putc,"Password Matched");
            lcd_gotoxy(1,2);
            printf(lcd_putc,"Door Closing....");
             fprintf(ZIGBEE,"\r\n PASSWORD MATCHED.  DOOR CLOSING.....r\n",);  delay_ms(700);
             fprintf(ZIGBEE,"\r\n -----------------------------------------------\r\n");    delay_ms(700);
           delay_ms(2000);
           output_low(pin_c4);output_high(pin_c5);
            output_low(pin_c7);  //relay on
             delay_ms(1000);
             goto y;
}


else
{           output_high(pin_c3);
             printf(lcd_putc,"\f");
            lcd_gotoxy(1,1);
            printf(lcd_putc,"YOU R Entered");
            lcd_gotoxy(1,2);
            printf(lcd_putc,"Wrong Password***");
            beep();
            fprintf(ZIGBEE,"\r\n Wrong Password Entry.Pls Check****\r\n");    delay_ms(700);
            fprintf(ZIGBEE,"\r\n -----------------------------------------------\r\n");    delay_ms(700);
            delay_ms(2000);
           output_low(pin_c3);
           goto y;
            

}


} //i== 4 closed
  
       
     
   } //WHILE
}  //MAIN




