#define NULL 0
#include <iostream>
using namespace std;

//global variables
double *v;
int count;
int size;

//Initializes global varaibles
void Initialize()
{
	v=new double[size]; //allocating memory
	count=0; // initalized to zero such that count will correletate to index number of last filled in element
	size=2;
}

//Clears the memory
void Finalize()
{
	delete []v;
}

//Doubles the size of the array
//sc of debut old/new capacity info
void Grow()
{
		double *nv;
		nv = new double[2*size];
		for(int i = 0; i < count; i++)
		{
			nv[i] = v[i];
		}
		size=size*2;
		v = nv;
	cout << "Vector grown.\n"
	     << "Previous capicity: " << count << " elements.\n"
	     << "New capacity: " << size << " elements.\n" << endl;
	     

}

//Adds a new element to the end of the array
//sc adding enough elements to grow vector
void AddElement() 
{
	double newElement;
	cin >> newElement;
	v[count] = newElement;
	count+=1;
}

//prints the vector as is
void PrintVector()
{
	for(int i = 0; i < count; i++)
	{
		cout << v[i] << endl;
	}
}
//function to remove last element without changing total array size
//sc error message if vecor empty, sc sucessful removal
void RemoveElement(){
	if(count==0){
		cout<<"There are no more values remaining"<<endl;
	}
	else{
	v[count]=0;	
	}
count=count-1;
}


//ask user for valid index and new element, shift the rest further down
//sc error message for invalid index, output with several elements at intermediate positions
void InsertElement(){
	int index;
	int ele;
	cout<< "Enter the index of new element: ";
	cin>> index;
	while ((index<0)||(index>size)){ //should this be size or count? should they be able to enter with gaps in the middle
		cout<<"Please enter a valid index: ";
		cin>>index;
		}
	cout<<"Enter the new element: ";
	cin>>ele;//don't need to check for validity?
	for(int i=size; i>index; i--){
		v[i]=v[i-1];  //alt: i=size-1; v[i+1]=v[i]
	}
	v[index]=ele; // i think we had problems with shifting other elements
	count=count+1;
}


//function to half total array size
//sc working correctly
void Shrink(){
		double *sv; //starting with same format as grow()
		sv = new double[size/2];//what happens if size is odd?
		for(int i = 0; i < count; i++)
		{
			sv[i] = v[i];// copying info
		}
		size=size/2;
		v = sv;
 		 cout << "Vector shrunk.\n"
            	      << "Previous capicity: " << count << " elements.\n"
                      << "New capacity: " << size << " elements.\n" << endl;
}


//Main program
int main()
{
Initialize();
int choice;

do
{

// Menu selection for user
cout
<< " 1 - Print Array.\n"
<< " 2 - Append element at the end.\n"
<< " 3 - Remove last element.\n"
<< " 4 - Insert one element.\n"
<< " 5 - Exit.\n"
<< " Select an option: ";
cin >> choice;

//Start of the cases
switch (choice)
{
case 1:
{
	PrintVector();
	break;
}
case 2:
{
	if (count == size) {
		Grow();
	}
	cout << "You selected 'Append element at the end'.\n";
	cout << "Enter new Element:\n";
	AddElement();
	break;
}
case 3:
{
	//code to remove the last element of the array
	RemoveElement();
	double sz= .3*size;
	if(count<sz){
		Shrink();
	}
	break;
}
case 4:
{
	//code to insert one element inisde of the array
	cout << "You selected 'Insert one element'\n";
	if (count == size) {
		Grow();
	}
	InsertElement();
	break;
}
case 5:
{
	//Ends Program
	cout << "End of Program.\n";
	break;
}
default:
	//Prints out this string if user insert an invalid value
	cout << "Not a Valid Choice. \n"
	<< "Choose again.\n";
break;
}

}
while (choice !=5);
	return 0;
}

