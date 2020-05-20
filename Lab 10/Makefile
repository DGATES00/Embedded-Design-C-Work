myrobotArm: RoboticArm.o main.o WiimoteRobot.o 

	g++ RoboticArm.o main.o WiimoteRobot.o -o myrobotArm	



main.o: main.cpp RoboticArm.h WiimoteRobot.h

	g++ -g -c main.cpp



RoboticArm.o: RoboticArm.cpp RoboticArm.h

	g++ -g -c RoboticArm.cpp

 

WiimoteRobot.o: WiimoteRobot.cpp WiimoteRobot.h

	g++ -g -c WiimoteRobot.cpp



clean:

	rm main.o RoboticArm.o WiimoteRobot.o myrobotArm

