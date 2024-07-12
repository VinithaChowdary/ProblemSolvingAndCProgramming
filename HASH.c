#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>

#define NAME 256
#define SIZE 10

typedef struct person {
    char name[NAME];
    int age;
    //add more information later
}person;

unsigned int hash(char* name) {//collisons occur 
/* delt with in two ways open addressing 
external chainings */
// liner probing method (just checks for next available hash value)

    int length=strnlen(name,NAME);//length comparison
    unsigned int hash_value;
    for(int i=0;i<length;i++){
    hash_value += name[i];//creating a hash value for database
    hash_value=(hash_value * name[i]) % SIZE;//creating a hash value for database
    }
}
person *hash_table[SIZE];

void ini_hash_table(){//initializing hash table by setting all spaces ot null values
     for(int  i=0;i<=SIZE;i++){
        hash_table[i] = NULL;
    }
}
void show(){//print the table
    for(int i=0;i<SIZE;i++){
        if(hash_table[i] == NULL){
        printf("\t%i\t---\n",i);
            }else{
            printf("\t%i\t%s\n",i,hash_table[i]->name);
        }
    }
}
bool push(person *p){
    if(p==NULL) return false;// condition checking for null pointer
    int index=hash(p->name);//index for location in the table to insert a string
    if(hash_table[index]!=NULL){//to check if space is available to add str
        return false;
    }
    hash_table[index]=p;//points to the available space
    return true;
}
person *srch(char *name){//search a person in the table
    int index=hash(name);
    if (hash_table[index] !=NULL && 
    strncmp(hash_table[index]->name,name,SIZE)==0){
        return hash_table[index];
    }else{
        return NULL;
    }
}
person *pop(char *name){
     int index=hash(name);
    if (hash_table[index] !=NULL && 
    strncmp(hash_table[index]->name,name,SIZE)==0){
        person *tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp;//to free tmp thats allocated on     the heap
    }else{
        return NULL;
    }

}

int main(){
    ini_hash_table();

    person jacob={.name="Jacob",.age=14};
    person jack={.name="Jack",.age=24};
    person george={.name="George",.age=19};

    push(&jacob);
    push(&jack);
    push(&george);
    show();

    
}