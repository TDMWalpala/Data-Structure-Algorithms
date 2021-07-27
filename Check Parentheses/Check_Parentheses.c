#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
struct stack
{
    char array[MAX];
    int top;
}st;
void push(char ele)
{
    if(st.top == MAX-1)
    {
        printf("\nstack is full");
    }else
    {
        st.top++;
        st.array[st.top] = ele;
    }
}
char pop()
{
    if(st.top == -1)
    {
        printf("stack is emply");
    }else
    {
        char out;
        out = st.array[st.top];
        st.top--;
        return out;
    }
}


int main()
{
 st.top = -1;
 char exp[MAX], temp;
 int i, flag = 1;
 printf("Enter an expression : ");
 gets(exp);
 for(i=0; i<strlen(exp); i++)
 {
     if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            {
                push(exp[i]);
            }

     if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
            {
                if(st.top==-1)
                {
                    flag=0;
                }
                else
                {
                    temp = pop();
                    if(exp[i]==')' && (temp=='{' || temp=='['))
                        {
                            flag=0;
                        }
                    if(exp[i]=='}' && (temp=='(' || temp=='['))
                        {
                            flag=0;
                        }
                    if(exp[i]==']' && (temp=='(' || temp=='{'))
                        {
                            flag=0;
                        }

                }
            }

 }
 if(st.top>=0)
 {
     flag=0;
 }
 if(flag==1)
 {
     printf("\nValid expression");
 }
 else
 {
     printf("\nInvalid expression");
 }

}
