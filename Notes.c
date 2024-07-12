#include <stdio.h>
#include <stdlib.h>
#define LIMIT 20
int arrA[LIMIT][LIMIT];
int arrB[LIMIT][LIMIT];
int arrC[LIMIT][LIMIT];



void pushB(int a,int b){    //to enter elements in B
    int u;
    for (int w=1;w<=a;w++){
        for(int q=1;q<=b;q++){
            printf("enter element a(%d,%d)",w,q);
            scanf("%d",&u);
            arrB[w][q]=u;
        }
    }

}

void sum(int a,int b){         //to compute sum 
    for(int w=1;w<=a;w++){
        for(int q=1;q<=b;q++){
            arrC[w][q]=(arrA[w][q])+(arrB[w][q]);

        }
    }
}

void pushA(int a,int b){    //to enter elements in A
    int u;
    for (int w=1;w<=a;w++){
        for(int q=1;q<=b;q++){
            printf("enter element a(%d,%d)",w,q);
            scanf("%d",&u);
            arrA[w][q]=u;
        }
    }

}
void print(int a,int b){        //to print the sum 
    for (int w=1;w<=a;w++){
        for(int q=1;q<=b;q++){
            printf("sum(%d,%d)=%d\n",w,q,arrC[w][q]);
            
        }
    }
}

int main(){
    int x,i,j;
    printf("enter i:");
    scanf("%d",&i);
    printf("enter j:");
    scanf("%d",&j); 
    while(1){
        printf("1.Add elements in A:\n");
                printf("2.Add elements in B:\n");
                printf("3.Sum of elements:\n");
                printf("4.Display elements:\n");
                printf("5.Exit\n");
                scanf("%d",&x);
                switch(x){
                    case 1:
                    pushA(i,j);
                    break;
                    case 2:
                    pushB(i,j);
                    break;
                    case 3:
                    sum(i,j);
                    break;
                    case 4:
                    print(i,j);
                    break;
                    case 5:
                    exit(0);
                    default:
                    printf("invalid");
        }
    }
}






