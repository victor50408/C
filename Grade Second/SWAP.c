#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;

void create_list(int num[],int len,NODE **head,int a,int b,NODE **n1,NODE **n2){
    NODE *current = NULL;
    NODE *previous = NULL;
    for(int i=0;i<len;i++){
        current = (NODE *)malloc(sizeof(NODE));
        if(i == a) *n1 = current;
        if(i == b) *n2 = current;
        printf("%p ",current);
        current->val = num[i];
        if(i==0){
            (*head)->right = current;
            current->left = *head;
        }else{
            previous->right = current;
            current->left = previous;
            if(i == len-1){
                current->right = *head;
                (*head)->left = current;
            }
        }
        previous = current;
    }
}


void SWAP(NODE **N1,NODE **N2){
    NODE *N1_pre = (*N1)->left;
    NODE *N2_next = (*N2)->right;
    NODE *temp = *N2;

        (*N1)->left = (temp)->left;
        (temp)->left->right = *N1;

        N1_pre->right = *N2;
        (*N2)->left = N1_pre;

        (*N2)->right = (*N1)->right;
        (*N1)->right->left = *N2;

        (*N1)->right = N2_next;
        N2_next->left = *N1;        
}

void print_list(NODE **head){
    puts("");
    NODE *current = (*head)->right;
    while(current != *head){
        printf("%d ",current->val);
        current = current->right;
    }
    puts("");
}


int main(){
    NODE *head = (NODE *)malloc(sizeof(NODE));
    NODE *n1 = (NODE *)malloc(sizeof(NODE));
    NODE *n2 = (NODE *)malloc(sizeof(NODE));

    printf("%p ",head);
    int a[] = {1,5,3,7,2};
    create_list(a,sizeof(a)/sizeof(a[0]),&head,2,3,&n1,&n2);
    print_list(&head);

    SWAP(&n1,&n2);
    print_list(&head);

    system("pause");
}