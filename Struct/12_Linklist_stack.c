#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char *name;
    struct node *link;
};
typedef struct node Node;

// C1 -> C0 -> bottom -> NULL
void push(Node **top,char *name){
    Node *current = (Node *)malloc(sizeof(Node));
    current->name = name;
    current->link = *top;//connect previous node
    *top = current;
}


void print_list(Node *P){
    if(P == NULL){
        printf("Empty!!!\n");
    }else{
        while (P != NULL){
        printf("%s ",P->name);
        P = P->link;
        }        
    }
    puts("");
}

int main(){
    
    Node *bottom = NULL;
    push(&bottom,"A");
    push(&bottom,"B");
    push(&bottom,"C");
    print_list(bottom);



    system("pause");
}