button: WiimoteBtns.o main.o
        g++ WiimoteBtns.o main.o button

WiimoteBtns.o: WiimoteBtns.cpp WiimoteBtns.h
               g++ -c WiimoteBtns.cpp

main.o: main.cpp WiimoteBtns.h
        g++ -c main.cpp

clean:
      rm WiimoteBtns.o main.o
