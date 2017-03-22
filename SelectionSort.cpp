#include <stdio.h>

	
int input[100]={8,1,5,4,3,9,2,6,7};

void Interchange(int i,int j)
{
	int temp = input[i];
	input[i]=input[j];
	input[j]=temp;
}

void SelectionSort(int n)
{
	int i,j,minIndex, temp;
	for (i=0;i<n-1;i++)
	{
		minIndex = i;
		for( j=i+1;j<n;j++)
		{
			if(input[j]<input[minIndex])
				minIndex = j;
		}
		if(minIndex != i)
			Interchange(i,minIndex);
	}
}


int main()
{

	int N= 9;
	for(int i = 0;i<N;i++)
		printf(" %d",input[i]);

	SelectionSort(N);
	printf("\n");
	for(int i = 0;i<N;i++)
		printf(" %d",input[i]);
	return 0;
}
