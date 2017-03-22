#include <stdio.h>

	
int input[100]={8,1,5,4,3,9,2,6,7};

void Interchange(int i,int j)
{
	int temp = input[i];
	input[i]=input[j];
	input[j]=temp;
}

int Partition(int low, int high)
{
	int p = low;
	int pivot =input[low];

	for(int i=low;i<=high;i++)
	{
		if(input[i]< pivot)
		{
			p++;
			Interchange(i,p);
		}
	}
	Interchange(p,low);
	printf("\n");
	for(int i = 0;i<9;i++)
		printf(" %d",input[i]);
	return (p);
	
}

void QuickSort(int low, int high)
{
	int pi;
	if(low<high)
	{
		pi=Partition(low,high);
		QuickSort(low,pi-1);
		QuickSort(pi+1,high);
	}
}



int main()
{

	int N= 9;
	for(int i = 0;i<N;i++)
		printf(" %d",input[i]);

	QuickSort(0,8);
	printf("\n");
	for(int i = 0;i<N;i++)
		printf(" %d",input[i]);
	return 0;
}
