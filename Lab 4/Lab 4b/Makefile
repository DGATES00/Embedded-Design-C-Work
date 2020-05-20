accel: WiimoteAccel.o WiimoteAccelMain.o

        g++ WiimoteAccel.o WiimoteAccelMain.o accel

WiimoteAccel.o: WiimoteAccel.cpp WiimoteAccel.h

               g++ -c WiimoteAccel.cpp
               
main.o: WiimoteAccelMain.cpp WiimoteAccel.h

        g++ -c WiimoteAccelMain.cpp

clean:

      rm WiimoteAccel.o WiimoteAccelMain.o

