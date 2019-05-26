
void forword1()
        {
        output_high(pin_C2);             //Enable L293D  1
        output_high(pin_C3);             //Make positive of motor 1
        output_low(pin_D0);             //Make negative of motor 0
        }
       

void forword2()
         {
         output_high(pin_C1);             //Enable L293D 2
         output_high(pin_D1);             //Make positive of motor 1
         output_low(pin_C0);             //Make negative of motor 0
         }
   //left turn robo

void backword1()
         {
        output_high(pin_C2);             //Enable L293D  1
        output_low(pin_C3);             //Make positive of motor 0
        output_high(pin_D0);             //Make negative of motor 1
         }


void backword2()
            {
            output_high(pin_C1);             //Enable L293D 2
            output_low(pin_D1);             //Make positive of motor 1
            output_high(pin_C0);             //Make negative of motor 0
            }


//left 
   //left turn robo

void left1()
         {
        output_high(pin_C2);             //Enable L293D  1
        output_low(pin_C3);             //Make positive of motor 0
        output_high(pin_D0);             //Make negative of motor 1
         }


void left2()
            {
            output_high(pin_C1);             //Enable L293D 2
            output_high(pin_D1);             //Make positive of motor 1
            output_low(pin_C0);             //Make negative of motor 0
            }


//right

void right1()
         {
        output_high(pin_C2);             //Enable L293D  1
        output_high(pin_C3);             //Make positive of motor 0
        output_low(pin_D0);             //Make negative of motor 1
         }


void right2()
            {
            output_high(pin_C1);             //Enable L293D 2
            output_low(pin_D1);             //Make positive of motor 1
            output_high(pin_C0);             //Make negative of motor 0
            }



//stop the motore

void stop1()
         {
         output_low(pin_C2);             //Enable L293D  0
         output_low(pin_C3);             //Make positive of motor 0
         output_low(pin_D0);             //Make negative of motor 0
         }


void stop2()
         {
        output_low(pin_C1);             //Enable L293D 2
        output_low(pin_D1);             //Make positive of motor 0
        output_low(pin_C0);             //Make negative of motor 0
        }
