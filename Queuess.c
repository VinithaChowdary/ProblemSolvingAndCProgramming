#include <stdio.h>
#include <string.h>
#include <stdlib.h>


# define SIZE 100
void enqueue();
void dequeue();
void show();
int Queue[SIZE];
int rear = - 1;
int Front = - 1;

void enqueue();
void dequeue();
void show();

int main()
{
    int ch,n;
    while (1)
    {
        printf("\n1.Enqueue \n");
        printf("2.Dequeue \n");
        printf("3.Display \n");
        printf("3.Search \n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            show();
            break;
            case 4:
            exit(0);
            default:
            printf("Incorrect choice \n");
        } 
    } 
} 
 
void enqueue()
{
    int n,a;
    if (rear == SIZE - 1){
       printf("Overflow \n");
    }
    else
    {
        if (Front == - 1){
        Front = 0; 
        printf("No.of elements to be enqueued\n");
        scanf("%d", &n);
            for(int i = 0; i < n; i++){
            printf("Values:");
            scanf("%d",&a);        
            rear ++;
            Queue[rear] = a;
            }
        } 
    }
}
 
void dequeue()
{
    if (Front == - 1 || Front > rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", Queue[Front]);
        Front = Front + 1;
    }
} 
 
void show()
{
    
    if (Front == - 1){
        printf("Empty Queue \n");
    }
    else
    {
        printf("Queue: \n");
        for (int i = Front; i <=rear; ++i){
            printf("%d --", Queue[i]);
    }
}
} 

void srch(int value){

}

