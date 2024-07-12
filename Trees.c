#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>

typedef struct treenode{ //structure of a tree node
    int value;
    struct treenode *left;
    struct treenode *right;
}treenode;

treenode *createnode(int value){ //function that returns a pointer
    treenode *result = malloc(sizeof(treenode));//memory allocation on the heap
if (result != NULL){
    result->left = NULL;
    result->right = NULL;
    result->value = value;
    }
return result;
}
   
void tabs(int x){
    for(int i=0; i<x; i++){
        printf("\t");
    }
}
void showrec(treenode *root,int level){//recursive function that is not called in main
    if (root == NULL){
        tabs(level);
        printf("---------\n");
        return;
    }
    tabs(level);
    printf("value=%d\n",root->value);
    tabs(level);

    printf("left:\n");
    showrec(root->left,level+1);
    tabs(level);

    printf("right:\n");
    showrec(root->right,level +1);
    tabs(level);
}
void show(treenode *root){//this function holds the recursive function and is called in called
    showrec(root,0);   
}
treenode *Right(treenode* root, int value) {
  root->right = createnode(value);
  return root->right;
}
treenode *Left(treenode* root, int value) {
  root->left = createnode(value);
  return root->left;
}
int main(){
    treenode *a = createnode(12);
    treenode *b = createnode(13);
    treenode *c = createnode(14);
    treenode *d= createnode(15);
    treenode *e = createnode(16);

    a->left=b;
    a->right=c;
    c->left=d;
    c->right=e;

    show(a);

    free(a);
    free(b);
    free(c);
    free(d);    
    free(e);

}

