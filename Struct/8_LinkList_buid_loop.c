#include <stdio.h>
#include <stdlib.h>

struct node{
    char name;
    struct node *link;
};
typedef struct node Node;


int main(){
    char letter[5] = {'A','B','C','D','E'};
    Node NODE[5];
    
    for(int i=0;i<5;i++){
        NODE[i].name = letter[i];
        if(i == 4){
            NODE[i].link = NULL;
        }else{
            NODE[i].link = &NODE[i+1];
        }
    }

    Node *current = &NODE[0];
    while(current != NULL){
        printf("%c %p\n",current->name,current);
        current = current->link;
    }


    system("pause");
}
