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
bool push(treenode **rootptr, int value){//double pointer is taken so that we can change the root value if the pointer is null
    treenode *root = *rootptr;
    if(root == NULL){
        (*rootptr) = createnode(value);
        return true;
    }
    if(value == root->value){
    return false;
    }
    if(value < root->value){
        return push(&(root->left), value);
    }else{
        return push(&(root->right), value);
    }
}

bool srch(treenode *root, int value){
    if(root == NULL)return false;
    if(value == root->value){
    return true;
    }
    if(value < root->value){
        return srch(&(root->left), value);
    }else{
        return srch(&(root->right), value);
    }
}
int main(){
treenode *root = NULL;

push(&root,13);
push(&root,15);
push(&root,17);
push(&root,21);
push(&root,2);
push(&root,27);
push(&root,26);
push(&root,9);


show(root);

}