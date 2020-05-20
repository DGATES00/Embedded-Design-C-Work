#include "RoboticArm.h"
#include "WiimoteRobot.h
#include <unistd.h>

/*

short accel;

class WiimoteToArm : public WiimoteRobot {







void ButtonEvent(int c2, short a){

 

 if (c2 == 3) {

     

       if (a < -100) {

          

          a = 0;

          accel = a;

          

       }

      

       else if (a < 100 && a > -100) {

       

          a = a + 100;

          a = (a*180)/(200);

          //std::cout << a << std::endl;

          accel = a;

          

          }

       

       else if (a > 100) {

       

            a = 180;

            accel = a;

          }



      }

    }





};



int main()



{

RoboticArm robotic_arm;

WiimoteToArm WR;



while (true)



  {



 int motor = WR.ListenButton();

 WR.ListenAccel();

 std::cout << accel << std::endl;

 robotic_arm.MoveServo(motor, accel, 45);



       }

       

  }

*/

int main ()

{

RoboticArm robotic_arm;





robotic_arm.MoveServo(1, 0, 90);

robotic_arm.MoveServo(4, 180, 90);

sleep(3);

robotic_arm.MoveServo(4, 0, 90);

sleep(1);

robotic_arm.MoveServo(1, 90, 180);

robotic_arm.MoveServo(3, 180, 180); 

robotic_arm.MoveServo(4, 180, 180);

robotic_arm.MoveServo(2, 180, 180);

sleep(3);

robotic_arm.MoveServo(0, 90, 30);

robotic_arm.MoveServo(1, 90, 45);

robotic_arm.MoveServo(2, 90, 90);

robotic_arm.MoveServo(3, 90, 90);

robotic_arm.MoveServo(4, 90, 90);

sleep(1);

}

