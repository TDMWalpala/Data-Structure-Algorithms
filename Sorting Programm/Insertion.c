#include <stdio.h>
#include <stdlib.h>

void main()
{
	int array[5]={5,1,3,4,2};
	int temp,n=5,i,j,x;
    printf("Befor sorting : ");
	for(int i=0; i<n; i++)
	{
		printf("%d, ", array[i]);
	}

	for(i=1; i<n; i++)
	{
		x= array[i];
		j=i-1;

		while(j>=0 && array[j]>x)
		{
			array[j+1] = array[j];
			j = j-1;
		}

		array[j+1] = x;
		
	}
    printf("After sorting :");
	for(i=0; i<n; i++)
	{
		printf("%d, ", array[i]);
	}

	//return 0;
}