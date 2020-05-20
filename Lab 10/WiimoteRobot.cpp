#include <stdlib.h>



#include <fcntl.h>



#include <unistd.h>



#include <iostream>

#include "WiimoteRobot.h"



using namespace std;



  WiimoteRobot::WiimoteRobot(){

 	

   fdButton = open("/dev/input/event2", O_RDONLY | O_NONBLOCK); //opening file, event 0

   fdAccel = open("/dev/input/event0", O_RDONLY); //opening file, event 0



    if (fdAccel == -1 || fdButton == -1) //accounting for errors in loading the file
	    {
		    cout << "Error: Could not open event file - forgot sudo? \n";

		    exit (1);

	  }}

     

   int WiimoteRobot::ListenButton() {

		  // reading a packet of 16 bytes from the Wiimote



		  char buffer[32];

		  read(fdButton, buffer, 32);


		  // extract the specific values from the 32 byte packet



		   int code = buffer[10];

       int value = buffer[12];


       if(value == 1){

       switch (code){

         case 106: // right on d-pad

             return 0; //'base'

             

         case 108: // down on d-pad

             return 1; // 'bicep'

             

         case 105: //left on d-pad

             return 2; // 'elbow'

         

         case 103: // up on d-pad

             return 3; // 'wrist'

         

         case 48: // 'A' button

             return 4; //'gripper'

           }

         }

         else {

              return 5;

         }

    

}



 void WiimoteRobot::ListenAccel() {
 

		  // reading a packet of 16 bytes from the Wiimote

		  char buffer[16];

		  read(fdAccel, buffer, 16);


		  // extract the specific values from the 16 byte packet


		   int code2 = buffer[10];

      short accel = * (short *) (buffer + 12);
       
      ButtonEvent(code2, accel);
      
      // AccelButtonEvent(code2, accel);
}




/*
    void WiimoteRobot::AccelButtonEvent(int c, short a) {
    
  if(c == 3){
       cout << "Code = " << c << ", acceleration ="  << a << endl;
       }

  }
 */
   void WiimoteRobot::ButtonEvent(int c1, short v){

    std::cout << "Code = " << c1 << ", value = " << v << '\n';

}



    

  WiimoteRobot::~WiimoteRobot() {



	close (fdButton);

  close (fdAccel);



	}

  

  