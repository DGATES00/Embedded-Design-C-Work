#include <iostream>
#include <string>
#include "GPIO.h" 

using namespace std;
	
int main(){
{
int choice;

do
{
cout << endl;
<< "Servo  1 - Base.\n"
<< "Servo  2 - Bicep.\n"
<< "Servo  3 - Elbow.\n"
<< "Servo  4 - Wrist.\n"
<< "Servo  5 - Gripper\n"
<< " Enter the Servo number: ";
cin >> choice;

switch (choice)
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
}	
