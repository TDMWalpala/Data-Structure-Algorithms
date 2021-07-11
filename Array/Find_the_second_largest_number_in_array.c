#include <stdio.h>
#include <stdlib.h>

/*WRITE A PROGRAMM TO FIND THE SECOND LARGEST OF n NUMBERS USING ARRAY*/
int main()
{
int i, j, largest, n, array[10];
    printf("Enter array size: ");
    scanf("%d", &n);
    array[n];
    for(i=0; i<n; i++)
    {
        printf("\nEnter value of index[%d] :",i);
        scanf("%d",&array[i]);
        largest = array[0];

    }
    for(i=0; i<n; i++)
    {
      if(largest<array[i])
      {
          largest = array[i];
          j=i;
      }

    }
    array[j]=0;
    largest = array[0];
    j=0;
    for(i=0; i<n; i++)
    {
      if(largest<array[i])
      {
          largest = array[i];
          j=i;
      }

    }


    printf("\nsecond largest number in array : %d",array[j]);
    return 0;
}
