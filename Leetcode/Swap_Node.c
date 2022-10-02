#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode Node;
struct ListNode *n1,*n2;


Node *create_Linklist(int NUM[],int len,int num1,int num2){
    Node *head = NULL;
    Node *current = NULL;
    Node *previous = NULL;

    for(int i=0;i<len;i++){
        current = (Node *)malloc(sizeof(Node));
        current->next = NULL;
        current->val = NUM[i];

        if(NUM[i] == num1){
            n1 = current;
        }
        if(NUM[i] == num2){
            n2 = current;
        }
        if(previous == NULL){
            head = current;
        }else{
            previous->next = current;
        }
        previous = current;
    }
    return head;
}

void print_list(Node *P){
    if(P == NULL){
        printf("Empty!!!\n");
    }else{
        while (P != NULL){
        printf("%d ",P->val);
        P = P->next;
        }        
    }
    puts("");
}

Node **SWAP(Node **head,Node *node1,Node *node2){
    if(node1 == node2) return head;

    Node *Prev1 = NULL;
    Node *Cur1 = *head;
    while(Cur1 != node1){
        Prev1 = Cur1;
        Cur1 = Cur1->next;
    }

    Node *Prev2 = NULL;
    Node *Cur2 = *head;
    while(Cur2 != node2){
        Prev2 = Cur2;
        Cur2 = Cur2->next;
    }

    if(Prev1 == NULL){
        *head = Cur2;
    }else{
        Prev1->next = Cur2;
    }

    if(Prev2 == NULL){
        *head = Cur1;
    }else{
        Prev2->next = Cur1;
    }

    Node *temp = Cur2->next;
    Cur2->next = Cur1->next;
    Cur1->next = temp;

}


int main(){
    struct ListNode *l1;
    int num1[]={5,4,2,3,0};
    
    l1 = create_Linklist(num1,sizeof(num1)/sizeof(num1[0]),5,4);
    print_list(l1);
    printf("!%p %p %p!\n",n1,n2,l1);
    SWAP(&l1,n1,n2);
    print_list(l1);

    system("pause");
}

