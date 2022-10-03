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
    Node *current = NULL;
    Node *p = NULL;

    for(int i=0;i<len;i++){
        current = (Node *)malloc(sizeof(Node));
        current->link = NULL;
        current->name = str[i];

        if(i == 0){
            head = current;
        }else{
            p->link = current;
        }
        p = current;
    }
    return head;
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

void Free_List(Node *P){
    Node *current,*temp;
    current = P;
    while (current != NULL){
        temp = current;
        current = current->link;
        free(temp);
    }

}

void Delete_node(Node *P,int location){
    int i=0;
    Node *previous = NULL;
    while(P != NULL){
        if(i == location-1){
            previous = P;
            previous->link = P->link->link;
        }
        i++;
        P = P->link;
    }

}

int main(){
    char *name[5] = {"A","B","C","D","E"};
    Node *head = create_Linklist(name,5);
    print_list(head);

    Delete_node(head,3);
    print_list(head);

    Free_List(head);
    //print_list(head);

    system("pause");
}