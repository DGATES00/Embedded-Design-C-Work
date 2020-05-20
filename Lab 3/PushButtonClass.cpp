
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cmath>

// Physical base address of GPIO
const unsigned gpio_address = 0x400d0000;

// Length of memory-mapped IO window
const unsigned gpio_size = 0xff;

const int gpio_led1_offset = 0x12C;  // Offset for LED1
const int gpio_led2_offset = 0x130;  // Offset for LED2
const int gpio_led3_offset = 0x134;  // Offset for LED3
const int gpio_led4_offset = 0x138;  // Offset for LED4
const int gpio_led5_offset = 0x13C;  // Offset for LED5
const int gpio_led6_offset = 0x140;  // Offset for LED6
const int gpio_led7_offset = 0x144;  // Offset for LED7
const int gpio_led8_offset = 0x148;  // Offset for LED8

const int gpio_sw1_offset = 0x14C;  // Offset for Switch 1
const int gpio_sw2_offset = 0x150;  // Offset for Switch 2
const int gpio_sw3_offset = 0x154;  // Offset for Switch 3
const int gpio_sw4_offset = 0x158;  // Offset for Switch 4
const int gpio_sw5_offset = 0x15C;  // Offset for Switch 5
const int gpio_sw6_offset = 0x160;  // Offset for Switch 6
const int gpio_sw7_offset = 0x164;  // Offset for Switch 7
const int gpio_sw8_offset = 0x168;  // Offset for Switch 8

const int gpio_pbtnl_offset = 0x16C;  // Offset for left push button
const int gpio_pbtnr_offset = 0x170;  // Offset for right push button
const int gpio_pbtnu_offset = 0x174;  // Offset for up push button
const int gpio_pbtnd_offset = 0x178;  // Offset for down push button
const int gpio_pbtnc_offset = 0x17C;  // Offset for center push button


class ZedBoard
{
	char *pBase;
	int fd;
public:

	ZedBoard()
	{

	fd = open( "/dev/mem", O_RDWR);
	pBase=(char *) mmap(NULL, gpio_size, PROT_READ | PROT_WRITE, MAP_SHARED,
	fd, gpio_address);
	// Check error
	if (pBase == MAP_FAILED)
	{
	perror("Mapping I/O memory failed - Did you run with 'sudo'?\n");
	}


	}

	
	~ZedBoard()
	{
	munmap(pBase, gpio_size);
	close(fd);

	}
	/**i
	* Write a 4-byte value at the specified general-purpose I/O location.
 	*
	* @param pBase Base address returned by 'mmap'.
 	* @parem offset Offset where device is mapped.
 	* @param value Value to be written.
 	*/

	void RegisterWrite(int offset, int value)
	{
		* (int *) (pBase + offset) = value;
	
	}
	/**
	 * Read a 4-byte value from the specified general-purpose I/O location.
	 *
	 * @param pBase Base address returned by 'mmap'.
	 * @param offset Offset where device is mapped.
	 * @return Value read.
	 */
	int RegisterRead(int offset)
	{
		return *(int *)(pBase + offset);
	}
};

	
/** Changes the state of an LED (ON OR OFF)
 * @param pBase      base address of I/O
 * @param ledNum    LED number (0 to 7)
 * @param state       State to change to (ON or OFF)
 */
void Write1Led(ZedBoard &zb, int ledNum, int state)
{
    int ledOffset= 4*ledNum; //finds the offset value
    int offset= 0x12C + ledOffset;
   zb.RegisterWrite (offset, state);
}

/** Reads the value of a switch
* - Uses base address of I/O
* @param pBase base address of I/O
* @param switchNum Switch number (0 to 7)
* @return Switch value read
*/
int Read1Switch(ZedBoard &zb, int switchNum){
    int offset = 0x14C + switchNum*4;
    return zb.RegisterRead(offset);
}

/** Set the state of the LEDs with the given value.
*
* @param pBase Base address for general-purpose I/O
* @param value Value between 0 and 255 written to the LEDs
*/
void WriteAllLeds(ZedBoard &zb, int value) {

int Bin[8];
int state;
int LedNum=0;
for(int i = 0; i <= 7; i++) {
Bin[i]  = value%2;
value = value/2;
}
for(int i = 0; i <= 7; i++) {
state = Bin[i];
Write1Led(zb, LedNum, state);
LedNum++;
}
}

/** Reads all the switches and returns their value in a single integer.
*
* @param pBase Base address for general-purpose I/O
* @return A value that represents the value of the switches
*/
int ReadAllSwitches(ZedBoard &zb){
	int Dec = 0;
	int temp=0;
	for(int i = 0; i <= 7; i++) {
		int switchNum = i;
		temp = Read1Switch(zb, switchNum)*(pow(2,i));
		Dec = Dec + temp;
}
	cout<<Dec<<endl;
	return Dec;
}


//Push Button Code 

int PushButtonGet(ZedBoard &zb,int value){
	int temp=0;
	int output;
	for (int i = 0 ; i <= 4 ; i++){
		int offset = 0x16C + i*4;
		temp = zb.RegisterRead(offset) ;
		if(temp==1){
		output=i+1;
		return output;	
	}
}
}

 
 




int main()
{
// Initialize
int LEDNum;
int state;
int switchNum;
int value;

//ZedBoard class 
ZedBoard zb;
//Request user input for the LED number and the state of the LED.

	cout<<"Please enter the LED number from 0 to 7 you want: "<<endl;
	cin>>LEDNum;
	cout<<"Please enter the state of the LED state: 0 or 1: "<<endl;
	cin>>state;
	Write1Led(zb, LEDNum, state);


	cout<<"Please enter the switch number from 0 to 7"<<endl;
	cin>>switchNum;
	Read1Switch(zb, switchNum);
	cout<<"Please enter the value from 0-255 that you want to pass into all 8 LEDS"<<endl;
	cin>>value;

WriteAllLeds(zb, value);


cout<<ReadAllSwitches(zb);


int count = 0;
int button=0;
int i = 0;
cout << "The program gets this far..." << endl;


//Initialize with the switch state

value=ReadAllSwitches(zb);
WriteAllLeds(zb,value);
count = value;
while(1==1) {

button = PushButtonGet(zb, value);
//cout<<"button is: " << button << endl;


//Switch 
switch (button) {
case 1:
	cout<< "button 1 is pressed: "<<endl;
	count=count<<1;
	cout<<count<<endl;
	WriteAllLeds(zb,count);
	usleep(500000);
break;
	
case 2:
	cout<<"button 2 is pressed: "<<endl;
	count=count>>1;
	cout<<count<<endl;
	WriteAllLeds(zb,count);

	usleep(500000);
break;

case 3:
	
	cout<< "button 3 is pressed "<<endl;
	count++;
	cout<<count<<endl;
	WriteAllLeds(zb, count);
	usleep(500000);
break;
case 4:
	cout<< "button 4 is pressed"<<endl;
	count--;
	cout<<count<<endl;
	WriteAllLeds(zb,count);
	usleep(500000);
break;
case 5:
	cout<<"button is 5"<<endl;
	value=ReadAllSwitches(zb);
	count=value;
	cout<<count<<endl;
	WriteAllLeds(zb,value);
	usleep(500000);
break;
default:
cout<< "button is: "<<button<<endl;
usleep(500000);
break;

}

}

}




