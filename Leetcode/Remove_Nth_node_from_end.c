#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode Node;

int count_node(struct ListNode* P){
    int counter = 0;
    while(P != NULL){
        counter++;
        P = P->next;
    }
    return counter;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* previous = NULL;
    struct ListNode* first = head;  
    int num_node = count_node(head);
    int i=0;
    while(head != NULL){        
        if(i == num_node-n){
            if(i == 0){
                if(head->next == NULL){
                    return NULL;
                }else{
                    first = head->next;
                    return first;
                }
            }else{
                previous->next = head->next;
            }
        }
        previous = head;
        head = head->next;            
        i++;
    }
    return first;
}

Node *create_Linklist(int NUM[],int len){
    Node *head = NULL;
    Node *current = NULL;
    Node *previous = NULL;

    for(int i=0;i<len;i++){
        current = (Node *)malloc(sizeof(Node));
        current->next = NULL;
        current->val = NUM[i];

        if(i==0){
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

int main(){
    struct ListNode *l1,*l2;
    int num1[]={1,2,3};

    l1 = create_Linklist(num1,sizeof(num1)/sizeof(num1[0]));
    print_list(l1);

    l2 = removeNthFromEnd(l1,2);
    print_list(l2);
    
    system("pause");
}