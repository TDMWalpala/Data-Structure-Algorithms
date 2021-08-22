#include <stdio.h>
#include <stdlib.h>

void main()
{
	int array[5]={5,1,3,4,2};
	int temp,n=5,i,j;
    printf("Befor sorting : ");
	for(int i=0; i<n; i++)
	{
		printf("%d, ", array[i]);
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
    printf("After sorting :");
	for(int i=0; i<n; i++)
	{
		printf("%d, ", array[i]);
	}

	//return 0;
}