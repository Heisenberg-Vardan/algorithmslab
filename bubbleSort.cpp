/*This program uses random variables to insert the elements of the array. 
If you want to see the result, uncomment the commented lines. */

#includ <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

class Bubble
{
	int size;
	int a[200000];
	public:
		Bubble()
		{
			cout<<"Enter the size: ";
			cin >> size;	
		}
		
		
		
		void swap(int &x, int &y)
		{
			int temp;
			temp = x;
			x = y;
			y = temp;
		}
		
		void getElements()
		{
			int i;
			//cout<<"Put the elements in: " <<endl;
			
			for(i=0; i<size; i++)
				a[i] = rand() % 100; // Generating random numbers between 0 to 99 and assigning it to array.
		}
		
		void bubbleSort()
		{
			int i,j;
			
			for(i=0; i<size; i++)
				for(j=0; j<size-1-i; j++)
				{
					if(a[j] > a[j+1])
					{
						swap(a[j], a[j+1]);
					}
				}
						
		}
		
		void display()
		{
			int i;
			for(i=0; i<size; i++)
				cout << a[i] << "  ";
		}
};


int main()
{
	Bubble obj;
	
	obj.getElements();
	//cout<<"Unsorted elements are: " << endl;
	//obj.display();
	clock_t start, end;
	double total_time;
	start = clock();	
	obj.bubbleSort();
	end = clock();
	total_time =(double) (end - start)/(CLOCKS_PER_SEC);
	//cout<<endl << "Sorted elements are: " << endl;
	//obj.display();
	cout<< endl << "The time taken is " << total_time <<" seconds."<<endl;
	
	return 0;
		
}
