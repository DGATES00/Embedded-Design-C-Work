

#include <stdlib.h>



#include <fcntl.h>



#include <unistd.h>



#include <sys/mman.h>



#include <iostream>



using namespace std;



#include "ZedBoard.h"





/**



 * Constructor Initialize general-purpose I/O



 *  - Opens access to physical memory /dev/mem



 *  - Maps memory at offset 'gpio_address' into virtual address space



 *



 * @param  None	Default constructor does not need arguments.



 * @return	None Default constructor does not return anything.



 */



using namespace std;



ZedBoard::ZedBoard(){

	cout << "\nStarting...." << endl;


	fd = open( "/dev/mem", O_RDWR);
	pBase = (char *) mmap(NULL,gpio_size,PROT_READ | PROT_WRITE, MAP_SHARED,fd,gpio_address);
	/* Check error */
 
	if (pBase == MAP_FAILED)
	{
		cerr << "Mapping I/O memory failed - Did you run with 'sudo'?\n";
		exit(1); // Returns 1 to the operating system;
	}		
}

/**
 * Destructor to close general-purpose I/O.
 * - Uses virtual address where I/O was mapped.
 * - Uses file descriptor previously returned by 'open'.
 *
 * @param  None	Destructor does not need arguments.
 * @return	None Destructor does not return anything.
 */

ZedBoard::~ZedBoard(){

	munmap(pBase, gpio_size);
	close(fd);	
	cout << "\nTerminating...." << endl;

}

/**
 * Write a 4-byte value at the specified general-purpose I/O location.
 *
 * - Uses base address returned by 'mmap'.
 * @parem offset	Offset where device is mapped.
 * @param value		Value to be written.
 */

void ZedBoard::RegisterWrite(int offset, int value)
{
	* (int *) (pBase + offset) = value;
}

/** Changes the state of an LED (ON or OFF)
* @param pBase base address of I/O
* @param ledNum LED number (0 to 7)
* @param state State to change to (ON or OFF)
*/

void ZedBoard::Write1Led(int ledNum, int state)
{
  int offset = 0x12C + ledNum*4;
  RegisterWrite(offset, state);
}

/**
 * Read a 4-byte value from the specified general-purpose I/O location.
 *
 * - Uses base address returned by 'mmap'.
 * @param offset	Offset where device is mapped.
 * @return		Value read.
 */
 
int ZedBoard::RegisterRead(int offset)
{
	return * (int *) (pBase + offset);
}
/**
 * Show lower 8 bits of integer value on LEDs
 *
 * - Calls Set1Led() to set all LEDs 
 * @param value	Value to show on LEDs
 */
void ZedBoard::SetLedNumber(int value)
{
	cout << "\nWriting to LEDs...." << endl;
	for(int i = 0; i < 8; i++) {// write to all LEDs
		cout << "LED " << i <<" offset: ";
		cout << hex << gpio_led1_offset + (i) << "  -  ";
		cout << "LED state: " << ((value / (1<<i)) % 2) << endl;
	}
}