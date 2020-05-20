#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#ifndef WIIMOTEBTNS_H
#define WIIMOTEBTNS_H


using namespace std;

class WiimoteBtns {
	public: 
	WiimoteBtns();
  ButtonEvent (int c, int v)
	void Listen(int fd);
	~WiimoteBtns();
 
	private: 
  int fd;

};
#endif


