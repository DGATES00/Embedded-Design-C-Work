#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class WiimoteAccel () {
	public: 
	WiimoteAccel () {
	fd = open("/dev/input/event0", O_RDONLY); //opening file, event 0
	if (fd == -1) //accounting for errors in loading the file
	{
		cout << "Error: Could not open event file - forgot sudo? \n";
		exit (1);
	}}

	Listen (int fd) {
	while (1) 
	{
		// reading a packet of 16 bytes from the Wiimote
		char buffer[16];
		read(fd, buffer, 16);

		// extract the specific values from the 32 byte packet
		int c = buffer[10];
		short a = * (short *) (buffer + 12);

		ButtonEvent(c, a);
}
}

	ButtonEvent (int c, short a) {
	cout << "Code = " << c << ", acceleration ="  << a << endl;
	}

	~WiimoteAccel () {
	close (fd);
	}
	private: 
	int fd;	
};

