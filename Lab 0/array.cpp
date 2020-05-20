#include <iostream>
#include <stdlib.h>
#include <algorithm>
using  namespace std;

void PrintArray(int v[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << v[i] <<endl;
	}
}

void RandomArray(int v[], int size)
{
	for(int i = 0; i < 10; i++)
	{
		v[i] = rand()%100;
	}
}

void SortArray(int v[], int size)
{
int j, min;
	for( int i = 0; i < size - 1; i++)
	{
		min = i;
		for(j = i+1; j < size; j++)
		{ 
			if(v[j] <  v[min])
			{
				min = j;
			}
		}
		swap(v[min], v[i]);
	}
}

int main()
{
int v[10];
RandomArray(v,10);
PrintArray(v,10);
SortArray(v,10);
PrintArray(v,10);
return 0;
}


