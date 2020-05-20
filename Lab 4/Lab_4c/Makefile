output: WiimoteAccel.o main.o ZedBoard.o
	g++ WiimoteAccel.o main.o ZedBoard.o -o output

WiimoteAccel.o: WiimoteAccel.cpp
	g++ -c WiimoteAccel.cpp
               
main.o: main.cpp
	g++ -g -c main.cpp
        
ZedBoard.o: ZedBoard.cpp
	g++ -g -c ZedBoard.cpp
           

clean:
	rm WiimoteAccel.o main.o ZedBoard.o output
