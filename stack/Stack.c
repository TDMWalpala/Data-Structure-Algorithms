#include <stdio.h>
#include <stdlib.h>
//global variable
int size, choice, ele, i;
//creating stack
struct stack
{
    int array[100];
    int top;
}st;
//inserting
void push(int ele)
{
    if(st.top == size-1)
    {
        printf("\nstack is full");
    }else
    {
        st.top++;
        printf("\nEnter a value ");
        scanf("%d", &ele);
        st.array[st.top] = ele;
    }
}
//removing
int pop()
{
    if(st.top == -1)
    {
        printf("stack is emply");
    }else
    {
        int out;
        out = st.array[st.top];
        st.top--;
        return out;
    }
}
//peek
int peek()
{
    int display;
    display = st.array[st.top];
    return display;
}
//display
void display()
{
    if(st.top>=0)
        {
            printf("\n\n Element in the stack");
            for(i=st.top; i>=0; i--)
            {
                printf("\n%d", st.array[i]);
            }

        }else
            {
                printf("No element to display");
            }

}

int main()
{
    st.top = -1;
    printf("Enter a stack size less than 100 ");
    scanf("%d", &size);
    printf("\nstack operation...");
    printf("\n\t1.pop\n\t2.push\n\t3.peek\n\t4.display\n\t5.exit");
    do{
        printf("\nEnter your choice :");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:{
                //push
                push(ele);break;
            }
            case 2:{
                //pop
                printf("%d", pop());break;
            }
            case 3:{
                //peek
                printf("%d", peek());break;
            }
            case 4:{
                //display
                display();break;
            }
            case 5:{
                //exit
                printf("Exit point");break;
            }
            default:{
                printf("\nEnter a correct choice (1,2,3,4,5)");
            }
        }
    }while(choice!=5);
    return 0;
}
