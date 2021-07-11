#include <stdio.h>
#include <stdlib.h>

/*WRITE A PROGRAM TO FIND THE MEAN OF n NUMBERS USING ARRAYS.*/
int main()
{
    int i, n, array[10], total=0;
    float  mean=0;
    printf("Enter array size: ");
    scanf("%d", &n);
    array[n];
    for(i=0; i<n; i++)
    {
        printf("\nEnter value of index[%d] :",i);
        scanf("%d",&array[i]);

    }
    for(i=0; i<n; i++)
    {
        total += array[1];
    }
    mean = total/n;
    printf("\nmean of the numbers: %0.2f",mean);

    return 0;
}
