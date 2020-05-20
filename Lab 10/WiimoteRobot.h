#include <iostream>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h>

#ifndef WIIMOTEROBOT_H

#define WIIMOTEROBOT_H



using namespace std;


class WiimoteRobot {

  int fdButton;

  int fdAccel;

  

  public: 

  WiimoteRobot();

  int ListenButton();

  void ListenAccel();

  

  //virtual void AccelButtonEvent(int c, short a);

  virtual void ButtonEvent(int c2, short a);

  ~WiimoteRobot();

  };

  #endif

