#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Selection
{
	int size;
	int a[200000];
	
	public:
		Selection()
		{
			cout<<"Enter the size: "<<endl;
			cin>>size;
		}
		
		
		void getElements()
		{
			for(int i=0; i<size; i++)
			{
				a[i] = rand() % 100;
			}
		}


		void selectionSort()
		{
			int i,j;
			int min;
	
			for(i=0; i<size-1; i++)
			{
				min = i;
		
				for(j=i+1; j<size; j++)
				{
					if(a[j] < a[min])
						min = j;
				}
				
				if(min != i)
					swap(a[min], a[i]);
		
			} // end outer for	
		}	


		void swap(int &x, int &y)
		{
			int temp;
			temp = x;
			x=y;
			y=temp;
		}

		void display()
		{
			for(int i=0; i<size; i++)
				cout<<a[i]<<" ";
		}
		
}; // end of class

int main()
{
	Selection obj;
	obj.getElements();
	
	clock_t start,end;
	double total_time;
	
	start=clock();
	obj.selectionSort();
	end = clock();

	
	total_time = (double)(end - start)/(CLOCKS_PER_SEC);
	
	cout<<endl<<"The time taken is " << total_time << "seconds."<<endl;
	
	return 0;
}
