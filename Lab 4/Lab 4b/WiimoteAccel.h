#include <iostream>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

#ifndef WIIMOTEBTNS_H

#define WIIMOTEBTNS_H





using namespace std;



class WiimoteAccel {

	public: 

	WiimoteAccel();

  ButtonEvent (int c, int a)

	void Listen(int fd);

	~WiimoteAccel();

 

	private: 

  int fd;



};

#endif

