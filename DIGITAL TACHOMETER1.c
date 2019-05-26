#include <16F877A.h>           //Microcontroller Used
#fuses    HS,NOWDT,PROTECT,brownout,put
#use      delay(clock=20M)          // operating Clock freequency
#include "flex_lcd.c"

void main()
{
   unsigned int16 value=0;
      
   lcd_init();

         printf(lcd_putc,"\f");
       lcd_gotoxy(4,1);
      printf(lcd_putc,"DIGITAL "); 
       lcd_gotoxy(3,2);
      printf(lcd_putc,"TACHOMETER");     
     delay_ms(2000);
     
     
    output_high(PIN_D2);
    output_high(PIN_D3);    
    output_high(PIN_C5);
    output_high(PIN_C4);
    delay_ms(500);   
    output_low(PIN_D2);
    output_low(PIN_D3);    
    output_low(PIN_C5);
    output_low(PIN_C4);
    delay_ms(500);
    output_high(PIN_D2);
    output_high(PIN_D3);    
    output_high(PIN_C5);
    output_high(PIN_C4);
    delay_ms(500);   
    output_low(PIN_D2);
    output_low(PIN_D3);    
    output_low(PIN_C5);
    output_low(PIN_C4);
          
     printf(lcd_putc,"\f");
      lcd_gotoxy(2,1);
      printf(lcd_putc,"LIVE SPEED"); 
       lcd_gotoxy(3,2);
         printf(lcd_putc,"RPM: %LU",value);
   while(1)
   {  
  
           /*
      set_timer1(0); 
      output_high(pin_c4);  
      setup_timer_1(t1_external | T1_DIV_BY_1);//c0
      delay_ms(100);         
      setup_timer_1(T1_DISABLED);
      value=get_timer1();
      output_low(pin_c4);
       
       printf(lcd_putc,"\f");
       lcd_gotoxy(2,1);
       printf(lcd_putc,"LIVE SPEED"); 
       lcd_gotoxy(5,2);
       printf(lcd_putc,"%LU",value); 
       delay_ms(500);
     
     */
         
        
           if(!input(pin_b0))
           {
           output_high(pin_d2);    
           value+=1;
      //  printf(lcd_putc,"\f");
      lcd_gotoxy(2,1);
      printf(lcd_putc,"LIVE SPEED"); 
      lcd_gotoxy(3,2);
      printf(lcd_putc,"RPM:%LU",value);
      output_low(pin_d2);
      delay_ms(50);
           } //while(!input(pin_b0));
       
    // else
    if(input(pin_b0))
     {
       if(value==1)
     {
      value=0; 
      printf(lcd_putc,"\f");
      lcd_gotoxy(2,1);
      printf(lcd_putc,"LIVE SPEED"); 
       lcd_gotoxy(5,2);
     lcd_gotoxy(3,2);
      printf(lcd_putc,"RPM: %LU",value);
      // output_low(pin_c4);
      delay_ms(50);
     }
     if(value>1)
     {
      value-=1;
      //  printf(lcd_putc,"\f");
      // lcd_gotoxy(2,1);
     // printf(lcd_putc,"LIVE SPEED"); 
       lcd_gotoxy(3,2);
      printf(lcd_putc,"RPM: %LU",value);
      // output_low(pin_c4);
      delay_ms(30);
     }
     
     } //else    
   
      }
                              
      }

    








