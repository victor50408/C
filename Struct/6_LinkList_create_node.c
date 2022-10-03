#include <stdio.h>
#include <stdlib.h>

struct node{
    char *name;
    int NO;
    struct node *link;
};
typedef struct node Node;

int main(){
    Node *head = (Node *)malloc(sizeof(Node)); //use pointer to create
    head->name = "first";
    head->NO = 1;
    head->link = NULL;


    Node head1; //direct declare
    head1.name = "first";
    head1.NO = 1;
    head1.link = NULL;

    system("pause");
}

