#include <stdio.h>
#include <stdlib.h>

struct node {
    char *name;
    struct node *link;
};
typedef struct node Node;

int main(){
    Node A,B,C; // LinkList : A -> B -> C
    A.name = "A";
    A.link = &B;

    A.link->name = "B"; //B.name = "B"
    A.link->link = &C;  //B.link = &C

    A.link->link->name = "C";
    A.link->link->link = NULL;

    Node *current = &A;
    while(current != NULL){
        printf("%s ",current->name);
        current = current->link;
    }

    system("pause");
}