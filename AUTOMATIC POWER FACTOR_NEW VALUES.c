/***********************************
TITLE: AUTOMATIC POWER FACTOR CONTROL SYSTEM (SUR)

MC : PIC16F877A,
LCD= B2 TO B7
A0= CURRENT SENSOR
D1= ZERO CROSSING DETETOR,
D2,D3,C4= LED'S,
D5,D6,D7 = 3 RELAYS FOR SWICHING CAPACITIVE BANK.
********************************/
#include <16F877A.h>           //Microcontroller Used
#fuses   HS,NOWDT,PROTECT,brownout,put
#use delay(clock=20M)          // operating Clock freequency
#include "flex_lcd.c"


//int CT=0;
 float CT1=0; 
 
void check()
{
if((!input(pin_d1)))
{   lcd_gotoxy(1,1);
   printf(lcd_putc,"error ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Please check");
   delay_ms(2000);
   break;
}


 if(CT1>35)
 {
   output_high(pin_D2);//    LED ON
  
    printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"PWR FACTOR: 0.99");
    lcd_gotoxy(1,2);
    printf(lcd_putc,"LEADING PWR FACTOR");
   delay_ms(1000 );
  }

 if(CT1==0)
     {
  //CT ADC VAUE CHECK UP
      printf(lcd_putc,"\f");
      lcd_gotoxy(3,1);
        printf(lcd_putc,"   NO LOAD");
         lcd_gotoxy(1,2);
        printf(lcd_putc,"-----------------");
      delay_ms(500);
     }

}


//main programming...........................................
void main()
{

   lcd_init();

   
  //health check
   output_high(pin_D2);       // Health check
   output_high(pin_D3); 
   output_high(pin_C4); 
   delay_ms(500);
   output_low(pin_D2);
   output_low(pin_D3);
   output_low(pin_C4);
   delay_ms(500);
   output_high(pin_D2);       // Health check
   output_high(pin_D3); 
   output_high(pin_C4); 
   delay_ms(500);
   output_low(pin_D2);
   output_low(pin_D3);
   output_low(pin_C4);
   delay_ms(500);
   
    setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(ALL_ANALOG);

   printf(lcd_putc,"\f");
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"AUTOMATIC POWER   ");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"FACTOR MONITORING ");
   delay_ms(3000);
   
   printf(lcd_putc,"\f");
      lcd_gotoxy(2,1);
   printf(lcd_putc,"AND CORRCTION   ");
   lcd_gotoxy(3,2);
   printf(lcd_putc,"   SYSTEM ");
   delay_ms(3000);
  
  
     
  while(1)
  {
  
     set_adc_channel(0);
      delay_ms(1);
     // CT = read_adc();
     CT1 = read_adc();
     delay_ms(1);
     
     
     
   //   printf(lcd_putc,"\f");
    // lcd_gotoxy(1,1);
    // printf(lcd_putc,"CT:%f ",CT1);
     //delay_ms(300);
     
  
  
  
  
     if(CT1==0)
     {
  //CT ADC VAUE CHECK UP
      printf(lcd_putc,"\f");
      lcd_gotoxy(3,1);
        printf(lcd_putc,"   NO LOAD");
         lcd_gotoxy(1,2);
        printf(lcd_putc,"-----------------");
      delay_ms(500);
     }
  
  

  /*
  
  
  if((!input(pin_d1)))
{ 
    printf(lcd_putc,"\f");
  lcd_gotoxy(1,1);
   printf(lcd_putc,"error    ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Please check");
   delay_ms(2000);
  // break;
}

*/


  else{
  
  //CT VALUES COMPARISION
  //if(CT1>10&&CT1<25)              //A0==1  CURRENT SENSR DETECT VALUE  
 if(CT1>40)  // >35
 {
   output_high(pin_D2);//    LED ON
  
    printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"PWR FACTOR: 0.99");
    lcd_gotoxy(1,2);
    printf(lcd_putc,"LEADING PWR FACTOR");
   delay_ms(1000 );
  }
 
 
 else{
  check();
  if(CT1<40)   //  <35          //A0==1  CURRENT SENSR DETECT VALUE  
  {
   output_low(pin_D2);//    LED ON
      
    printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"PWR FACTOR: 0.78");
    lcd_gotoxy(1,2);
    printf(lcd_putc,"LAGGING PWR FACTOR");
       delay_ms(10000 );
        output_high(pin_D5);
             delay_ms(1500);

        //set_adc_channel(0);
     // delay_ms(1);
        CT1 = read_adc();
     delay_ms(1);
    

    //  output_high(pin_D5);
    printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"CAPACITIVE LOAD");
    lcd_gotoxy(1,2);
    printf(lcd_putc,"IS ON");
    delay_ms(1000 );
    printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"PWR FACTOR: 0.93");
    lcd_gotoxy(1,2);
    printf(lcd_putc,"LEADING PWR FACTOR");
    delay_ms(10000 );
    check();
    //2nd
    printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"CAPACITIVE LOAD");
    lcd_gotoxy(1,2);
    printf(lcd_putc,"IS ON");
    delay_ms(1000 );
       output_high(pin_D6);
        printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"PWR FACTOR: 0.95");
    lcd_gotoxy(1,2);
    printf(lcd_putc,"LEADING PWR FACTOR");
        delay_ms(10000 );
    check();    
        //3rd
        printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"CAPACITIVE LOAD");
    lcd_gotoxy(1,2);
    printf(lcd_putc,"IS ON");
    delay_ms(1000 );
       output_high(pin_d7);
        printf(lcd_putc,"\f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"PWR FACTOR: 0.99");
    lcd_gotoxy(1,2);
    printf(lcd_putc,"LEADING PWR FACTOR");
       delay_ms(5000 );
   
  }  //if ct
 
 
 }  //else
    
    
  }// else    
  
  
  
  } //while close
      
}  //main close


