output: GPIO.o main.o 
	g++ GPIO.o main.o -o output	

GPIO.o: GPIO.cpp
	g++ -g -c GPIO.cpp

main.o: main.cpp
	g++ -g -c main.cpp

clean:
	rm GPIO.o main.o output

