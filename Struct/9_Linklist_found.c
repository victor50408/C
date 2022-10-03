#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *name;
    struct node *link;
};
typedef struct node Node;

Node *create_Linklist(char *str[],int len){
    Node *head = NULL;
    Node *current = NULL; //node
    Node *p = NULL;
    
    for(int i=0;i<len;i++){
        current = (Node *)malloc(sizeof(Node)); //create a node
        current->name = str[i];
        current->link = NULL;

        if(i == 0){
            head = current;
        }else{
            p->link = current; //connect previous node to current node
        }
        p = current; //record current node
    }
    return head;
}

Node *found(Node *P,char *target,int len){
    for(int i=0;i<len;i++){
        char *str = P->name;
        if(strcmp(str,target)==0){
            return P;
        }
        P = P->link;
    }
    return NULL;
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

void print_list(Node *P,int len){
    while(P != NULL){
        printf("%s %p\n",P->name,P);
        P = P->link;
    }
}

int main(){
    char *name[5] = {"A","B","C","D","E"};
    char target[10];

    printf("Enter the word that you wanna find>");
    scanf("%s",target);

    Node *head = create_Linklist(name,5);

    Node *location = found(head,target,5);
    if(location != NULL){
        printf("found!!! | %s %p\n",location->name,location);
    }else{
        printf("no found!!!\n");
    }
    print_list(head,5);
    Free_List(head);

    system("pause");
}
