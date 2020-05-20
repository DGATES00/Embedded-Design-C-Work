#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
using  namespace std;

void EnterArray(string v[], int size)
{
        for(int i = 0; i < size; i++)
        {
                cin >> v[i];
        }
}

void PrintArray(string v[], int size)
{
	for(int i = 0; i <  size; i++)
	{
		cout << v[i] << endl;
	}
}
void SortArray(string v[], int size)
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
string v[10];
EnterArray(v,10);
SortArray(v,10);
PrintArray(v,10);
return 0;
}




