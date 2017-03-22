#include <stdio.h>

	
int input[100]={8,1,5,4,3,9,2,6,7};

void Merge(int low,int mid,int high)
{
	int temp[100];

	int firstIndex= low;
	int i = low;
	int secondIndex = mid+1;
	while( (firstIndex<=mid) && (secondIndex<=high))
	{
		if(input[firstIndex] <= input[secondIndex])
		{
			temp[i]=input[firstIndex];
			firstIndex++;
		}
		else
		{
			temp[i] = input[secondIndex];
			secondIndex++;
		}
		i++;
	}

	if(firstIndex > mid)
	{
		for(int k=secondIndex;k<=high;k++)
		{
			temp[i]=input[k];
			i++;
		}
	}
	else
	{
		for(int k=firstIndex;k<=mid;k++)
		{
			temp[i]=input[k];
			i++;
		}
	}
	for(int k=low;k<=high;k++)
		input[k]=temp[k];

}

void MergeSort(int low, int high)
{
	if( low < high)
	{
		int mid = (high+low)/2;
		MergeSort(low,mid);
		MergeSort(mid+1,high);
		Merge(low,mid,high);
	}
}


int main()
{

	int N= 9;
	for(int i = 0;i<N;i++)
		printf(" %d",input[i]);

	MergeSort(0,8);
	printf("\n");
	for(int i = 0;i<N;i++)
		printf(" %d",input[i]);
	return 0;
}
