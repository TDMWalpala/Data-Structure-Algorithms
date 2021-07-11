#include <stdio.h>
#include <stdlib.h>

/*WRITE A PROGRAM TO PRINT THE POSITION OF THE SMALLEST  NUMBER OF n  NUMBERS USING ARRAYS.*/
int main()
{
    int i, j,small, n, array[10];
    printf("Enter array size: ");
    scanf("%d", &n);
    array[n];
    for(i=0; i<n; i++)
    {
        printf("\nEnter value of index[%d] :",i);
        scanf("%d",&array[i]);
        small = array[0];

    }
    for(i=0; i<n; i++)
    {
      if(small>array[i])
      {
          small = array[i];
          j = i;
      }

    }

    printf("/nposition is the smallest number in array : %d",j);

    return 0;

}
