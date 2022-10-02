#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode Node;

struct ListNode* reverse(struct ListNode* head){
    struct ListNode *current = head;
    struct ListNode *previous = NULL;
    struct ListNode *node = NULL;

    while(current != NULL){
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = current->val;

        if(previous == NULL){
            node->next = NULL;
        }else{
            node->next = previous;
        }
        previous = node;
        current = current->next;
    }

    return node;
}

Node *create_Linklist(int NUM[],int len){
    Node *head = NULL;
    Node *current = NULL;
    Node *previous = NULL;

    for(int i=0;i<len;i++){
        current = (Node *)malloc(sizeof(Node));
        current->val = NUM[i];
        current->next = NULL;

        if(i == 0){
            head = current;
        }else{
            previous->next = current;
        }
        previous = current;
    }
    return head;
}

void print_list(Node *P){
    while(P != NULL){
        printf("%d ",P->val);
        P = P->next;
    }
    puts("");
}


int main(){
    struct ListNode *l1;
    int num1[]={1,2,3,4,5,6};

    l1 = create_Linklist(num1,sizeof(num1)/sizeof(num1[0]));
    print_list(l1);

    l1 = reverse(l1);
    print_list(l1);

    system("pause");
}