#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode Node;

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

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode *current = head;
    struct ListNode *previous = NULL;
    struct ListNode *node = NULL;
    struct ListNode *Begin = NULL;
    struct ListNode *End = NULL;
    struct ListNode *Bottom = NULL;

    if(head == NULL) return head;
    if(head->next == NULL) return head;
    if(left == right) return head;

    int i = 1;
    while(current != NULL){
        if(i == left-1) Begin = current;

        if(i >= left && i <= right){
            node = (struct ListNode *)malloc(sizeof(struct ListNode));
            node->val = current->val;
            if(i == left){
                Bottom = node;
                node->next = NULL;                    
            }else{
                node->next = previous;
            }
            previous = node;
        }
        if(i == right+1){
            End = current;        
        }

        current = current->next;
        i++;
    }
    if(left == 1){
        Bottom->next = End;
        return node;
    }else if(right == i){
        Begin->next = node;
        Bottom->next = NULL;
        return head;
    }else{
        Begin->next = node;
        Bottom->next = End;
    }
    return head;
}

int main(){
    struct ListNode *l1;
    int num1[]={1,2,3,4,5};

    l1 = create_Linklist(num1,sizeof(num1)/sizeof(num1[0]));
    print_list(l1);

    l1 = reverseBetween(l1,4,5);
    print_list(l1);

    system("pause");
}

