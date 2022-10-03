#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char *name;
    struct node *link;
};
typedef struct node Node;


Node *create_Linklist(char *str[],int len){
    Node *head = NULL;
    Node *current = NULL; //node
    Node *p = NULL; //previous(前一次)
    
    for(int i=0;i<len;i++){
        current = (Node *)malloc(sizeof(Node)); //create a node
        current->name = str[i];
        current->link = NULL;

        if(i == 0){
            head = current;
        }else{
            p->link = current; //connect previous node to current node
        }
        p = current; //record current node (it will be the previous node from the next state)
    }
    return head;
}

void print_list(Node *P){
    while(P != NULL){
        printf("%s ",P->name);
        P = P->link;
    }
}


int main(){
    char *name[5] = {"A","B","777","D","E"};
    Node *head = create_Linklist(name,5);
    print_list(head);

    system("pause");
}