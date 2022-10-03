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

Node *search_node(Node *P,int location){
    int i=0;
    while(P != NULL){
        if(i == location){
            return P;
        }else{
            P = P->link;
        }
        i++;
    }
    return NULL;
}


void insert_node(Node *origin,int NO_node,char *name){
    Node *current = search_node(origin,NO_node);
    if(current != NULL){
        Node *new_node = (Node *)malloc(sizeof(Node));//create new node
        new_node->name = name;//input data

        /******************************
         
        current -> current.link (temp)
             (insert new_node)
        current -> new_node -> temp

        ********************************/
        Node *temp = current->link;//copy current next node to temp
        current->link = new_node;//connect current to new_node
        new_node->link = temp;//new_node connect to temp (current next)
    }else{
        printf("No found!!! | index out of range\n");
    }

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

void print_list(Node *P){
    while(P != NULL){
        printf("%s ",P->name);
        P = P->link;
    }
}


int main(){
    char *name[5] = {"A","B","C","D","E"};
    int location;
    char input[10];
    Node *head = create_Linklist(name,5);
    print_list(head);
    putchar('\n');

    printf("Enter the location and name to insert the list\n");
    printf("location>");
    scanf("%d",&location);
    printf("name>");
    scanf("%s",input);

    insert_node(head,location,input);
    print_list(head);

    Free_List(head);

    system("pause");
}