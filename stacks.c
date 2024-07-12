#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>


#define SIZE 10

int top = -1;
int ttp=-1;
int stack[SIZE];
int arr[SIZE];
void push();
void pop();
void show();
void srch(int x);
int swap(int i,int j);

int main()
{
    int choice;

    while (1)
    {
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.search and pop a certain element\n5.Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int a;
            printf("Enter no of elements to be added:");
            scanf("%d",&a);
            for(int i=0;i<a;i++){
            push();
            }
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
        int y;
        printf("Enter element to pop:");
        scanf("%d",&y);
        srch(y);
        break;
        case 5:
        exit(0);
        default:
            printf("\nInvalid choice!!");
        }
    }
}

void push()
{

    if (top == SIZE - 1)
    {
        printf("\nOverflow!!");
    }
    else
    { 
        int x;
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop( )
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element: %d", stack[top]);
        top = top - 1;
    }
}

void show()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", stack[i]);
    }
}

void srch(int y){
    int x;
    if (top == -1)
    {
    printf("\nUnderflow");
    }
    else{
        for (int i=top;i>=0;--i){
        if(stack[i]==y)
        {
         for(int j=i;j<top;j++){
            for(int u=j+1;u<top+1;u++){        
            x = stack[j];
            stack[j] = stack[u];
            stack[u] = x;
            j++;            
           }
           printf("\nPopped element: %d", stack[top]);
           top = top - 1;
        }                 
    }
}
}
}


