#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };
typedef struct ListNode Node;

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *current = head;       
    struct ListNode *less = NULL; 
    struct ListNode *large = NULL; 
    struct ListNode *previous_less = NULL;
    struct ListNode *previous_large = NULL;
    if(head == NULL) return NULL;

    while(current != NULL){
        if(current->val < x){
            if(previous_less == NULL){
                less = current;
            }else{
                previous_less->next = current;
            }
            previous_less = current;
        }else{
            if(previous_large == NULL){
                large = current;
            }else{
                previous_large->next = current;
            }
            previous_large = current;
        }
        current = current->next;
    }
    if(previous_less == NULL){
        return head;
    }
    if(previous_large == NULL){
        return head;
    }

    previous_less->next = large;
    previous_large->next = NULL;

    return less;
}

Node *create_Linklist(int NUM[],int len){
    Node *current = NULL;
    Node *previous = NULL;
    Node *head = NULL;

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
    int num1[]={1,2,3};

    l1 = create_Linklist(num1,sizeof(num1)/sizeof(num1[0]));
    print_list(l1);

    l1 = partition(l1,2);
    print_list(l1);

    system("pause");
}

