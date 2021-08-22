
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 10

void print_array(int *a, int len)
{
    int i;
    printf("\n--------\n");
    for (i=0; i<len; i++)
        printf("%d, ", a[i]);
    printf("\n--------\n");
}

void get_array(int *a, int len)
{
    int i;
    printf("\n\nArray Input: \n");
    for (i=0; i<len; i++) {
        printf("Enter array[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("\n");
}

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int choose_pivot(int i,int j )
{
    return((i+j) /2);
}

void quicksort(int list[],int m,int n)
{
    int key,i,j,k;
    if ( m < n) {
        k = choose_pivot(m,n);
        swap(&list[m],&list[k]);
        key = list[m];
        i = m+1;
        j = n;
        while (i <= j) {
            while ((i <= n) && (list[i] <= key))
                i++;
            while ((j >= m) && (list[j] > key))
                j--;
            if ( i < j)
                swap(&list[i],&list[j]);
        }
        swap(&list[m],&list[j]);

        quicksort(list,m,j-1);
        quicksort(list,j+1,n);
    }
}


int main()
{
    int a[MAX_ELEMENTS];
    get_array(a, MAX_ELEMENTS);
    printf("You Entered: ");
    print_array(a, MAX_ELEMENTS);
    printf("After Sorting: ");
    quicksort(a, 0, MAX_ELEMENTS-1);
    print_array(a, MAX_ELEMENTS);
}
