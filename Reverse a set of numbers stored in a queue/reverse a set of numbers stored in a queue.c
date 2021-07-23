#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int front=-1, rear=-1;
int queue[MAX];

int enqueue(int data, int n)
{
    if(rear==n-1)
    {
      printf("\nQueue is overflow");
    }else{
        if(front==-1 && rear== -1)
        {
            front=rear=0;
            queue[rear]=data;

        }else
        {
            rear++;
            queue[rear]=data;
        }
    }

}
void print()
{
    int i;
    printf("[");
    for(i=front;i<=rear;i++)
    {
        printf("%d,",queue[i]);
    }
    printf("]");
}

void reversequeue()
{
    int j,i,temp;
    for(i=front,j=rear;i<j;i++,j--)
    {
        temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
    }
}

int main()
{
    int n,data;
    printf("Enetr size of Queue :");
    scanf("%d",&n);
    printf("\nInsert data for queus :");
    int i=0;
    while(i<n)
    {
        scanf("%d",&data);
        enqueue(data,n);
        i++;
    }
    printf("Input : Q =");
    print();
    reversequeue();
    printf("\nOutput : Q =");
    print();

    return 0;
}
