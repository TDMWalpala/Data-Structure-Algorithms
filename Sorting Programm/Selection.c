#include <stdio.h>
#include <stdlib.h>

void main()
{
	int array[5]={5,1,3,4,2};
	int temp,n=5,i,j,min;
    printf("Befor sorting : ");
	for(int i=0; i<n; i++)
	{
		printf("%d, ", array[i]);
	}

	for(i=0; i<n-1; i++)
	{
		min=i;

		for(j=i+1; j<n; j++)
		{
			if(array[j]<array[min])
			{
				min=j;
			}
		}

		temp=array[i];
		array[i]=array[min];
		array[min]=temp;
	}
    printf("After sorting :");
	for(i=0; i<n; i++)
	{
		printf("%d, ", array[i]);
	}

	//return 0;
}