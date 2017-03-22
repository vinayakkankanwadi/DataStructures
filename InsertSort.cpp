#include <stdio.h>

	
int input[100]={8,1,5,4,3,9,2,6,7};

void Interchange(int i,int j)
{
	int temp = input[i];
	input[i]=input[j];
	input[j]=temp;
}

void InsertSort(int n)
{
	int i,j, temp;
	for (i=1;i<n;i++)
	{
		j= i;
		while(j>0 && input[j-1] > input[j])
		{
			Interchange(j,j-1);
			j--;
		}
	}
}


int main()
{

	int N= 9;
	for(int i = 0;i<N;i++)
		printf(" %d",input[i]);

	InsertSort(N);
	printf("\n");
	for(int i = 0;i<N;i++)
		printf(" %d",input[i]);
	return 0;
}
