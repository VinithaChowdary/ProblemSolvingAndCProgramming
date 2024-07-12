#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>

typedef struct node{
    int value;
    struct node *next;
}link;

void print(link *head){
    link *temp = head;
    while (temp != NULL){
    printf("%d-", temp->value);
    temp = temp->next;
    }
    printf("\n");
}
//function to create a new node

link *node(int value){      //return type id a pointer to a node
    link *n = malloc(sizeof(link));//memory allocation everytime the function is called...
    n->value = value;//assigns a value to a node
    n->next = NULL;//initializes the link
    return n;
}
 
link *push_head(link **head,link *node){ //taking a double pointer so that we can change the head pointer
node->next = *head;
*head = node;
return node;
}


link *push_node(link *node,link *newnode){//creating a new node and adding it after a particulat node
newnode->next = node->next;
node->next = newnode;
//basic swap function

}

link *srch(link *head,int data){ //search algorithm (just like in stack)
    link *tmp=head;
    while(tmp!=NULL){
        if(tmp->value==data)return tmp;
        tmp=tmp->next;
    }
    return NULL;
}

int main(){
link *head=NULL;
link *tmp;
link *temp;
int n,x,choice;
while(1){
    printf("\n1.Add Elements into the list\n2.Display List\n3.Add element\n4.Search\n5.Exit\n");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
        printf("No of value you wanna add:");//creating new nodes and adding them to the front of the list
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
        printf("Enter value:");
        scanf("%d",&x);
        tmp=node(x);
        push_head(&head,tmp);
        }
        break;
        case 2:
        print(head);
        break;
        case 3:
        int a,b;
        printf("1.At head\n2.insert inbetween\n");
        scanf("%d",&a);
        printf("Enter value:");
        scanf("%d",&b);
            switch(a){
                case 1:
                temp=node(b);
                push_head(&head,temp);
                break;
                case 2:
                int y;
                printf("Enter value u want to add after:");
                scanf("%d",&y);
                push_node(srch(head,y),node(b));
                break;
                default :
                printf("Invalid Input:");
            }
            break;
            case 4:
            int p;
            printf("Enter value u want to search for:");
            scanf("%d",&p);
            srch(head,p);
            printf("Found the node with value %d",p);
            break;
            case 5:
            exit(0);
            default :
            printf("Invalid Input");
return 0;
        }
    }
}
//code to delete a node to be written
