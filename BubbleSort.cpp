#include <stdio.h>

	
int input[100]={8,1,5,4,3,9,2,6,7};

void Interchange(int i,int j)
{
	int temp = input[i];
	input[i]=input[j];
	input[j]=temp;
}

void BubbleSort(int n)
{
	for (int i=n-1;i>0;--i)
	{
		for(int j=0;j<i;++j)
		{
			if(input[j+1]<input[j])
				Interchange(j+1,j);
		}
	}
}


int main()
{

	int N= 9;
	for(int i = 0;i<N;i++)
		printf(" %d",input[i]);

	BubbleSort(N);
	printf("\n");
	for(int i = 0;i<N;i++)
		printf(" %d",input[i]);
	return 0;
}
