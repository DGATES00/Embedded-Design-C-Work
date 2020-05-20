#include <iostream>



#include <stdlib.h>



#include <unistd.h>



#include <fcntl.h>



#ifndef WIIMOTEACCEL_H

#define WIIMOTEACCEL_H

using namespace std;


class WiimoteAccel {

      int fd;

	public: 
  WiimoteAccel();
  
  virtual void ButtonEvent(int c, int a);

	void Listen();

	~WiimoteAccel();
};



#endif



