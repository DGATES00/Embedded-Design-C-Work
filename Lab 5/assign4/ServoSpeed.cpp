#include <iostream>
#include <string>
#include <stdlib>
#include "GPIO.h" 

using namespace std;

void GPIO::GenerateVariablePWM(int period, int first_pulse,int last_pulse, int num_periods){
	int r = abs(last_pulse - first_pulse);
	GPIO::GeneratePWM(20000, (first_pulse + (r/num_periods)), 1);
}
int main(){

int servoNum;
int startPos;
int endPos;
int rotateSpeed;

do
{
cout << endl;
<< "Servo  1 - Base.\n"
<< "Servo  2 - Bicep.\n"
<< "Servo  3 - Elbow.\n"
<< "Servo  4 - Wrist.\n"
<< "Servo  5 - Gripper\n"
<< " Enter the Servo number: ";
cin >> servoNum;

switch (servoNum)
{
case 1:
	GPIO gpio(13);
	gpio.GeneratePWM(20000, 1500, 400); 
break;
case 2:
	GPIO gpio(10);
	gpio.GeneratePWM(20000, 1500, 400); 
break;
case 3:
	GPIO gpio(11);
	gpio.GeneratePWM(20000, 1500, 400); 
break;
case 4:
	GPIO gpio(12);
	gpio.GeneratePWM(20000, 1500, 400); 
break;
case 5:
	GPIO gpio(0);
	gpio.GeneratePWM(20000, 1500, 400); 
break;
default:
cout << "Not a Valid Choice. \n"
<< "Choose again.\n";
break;
}

}while (choice !=5);
return 0;
	
cout << " Enter the Start postion(angle between 0 and 180: ";
cin >> startPos;

cout << " Enter the End postion(angle between 0 and 180): ";
cin >> endPos;

cout << " Enter the Rotational speed given in degrees per second: ";
cin >> rotateSpeed;

int p = (endPos - startPos)/rotateSpeed

GPIO::GenerateVariablePWM(p, startPos, endPos, 50 )
}
 
