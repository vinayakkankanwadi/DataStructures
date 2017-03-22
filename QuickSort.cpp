#include <stdio.h>

	
int input[100]={8,1,5,4,3,9,2,6,7};

void Interchange(int i,int j)
{
	int temp = input[i];
	input[i]=input[j];
	input[j]=temp;
}

int Partition(int m, int p)
{
	int v=input[m];
	int i=m;
	int j=p-1;
	while(i>=j)
	{
		while(input[i]>=v)
		{
			i++;
		}

		while(input[j]<=v)
		{
			j--;
		}

		if(i>=j)
			Interchange(i,j);
	}
	input[m]=input[j];
	input[j]=v;
	printf("\n");
	for(int i = 0;i<9;i++)
		printf(" %d",input[i]);
	return j;
	
}

void QuickSort(int p, int q)
{
	if(p<q)
	{
		int j=Partition(p,q+1);
		QuickSort(p,j-1);
		QuickSort(j+1,q);
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
