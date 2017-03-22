#include <stdio.h>

	
int input[100]={8,1,5,4,3,9,2,6,7};

void Interchange(int i,int j)
{
	int temp = input[i];
	input[i]=input[j];
	input[j]=temp;
}

void Heapify(int n,int i)
{
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<n && input[l]>input[largest])
		largest =l;
	if(r<n && input[r]>input[largest])
		largest =r;

	if(largest != i)
	{
		Interchange(i,largest);
		Heapify(n,largest);	
	}
}

void HeapSort(int n)
{
	for (int i=n/2-1;i>=0;--i)
		Heapify(n,i);
	for (int i=n-1;i>=0;--i)
	{
		Interchange(0,i);
		Heapify(i,0);
	}
}


int main()
{

	int N= 9;
	for(int i = 0;i<N;i++)
		printf(" %d",input[i]);

	HeapSort(N);
	printf("\n");
	for(int i = 0;i<N;i++)
		printf(" %d",input[i]);
	return 0;
}
