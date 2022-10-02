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

struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* first = head;
    int node_num = count_node(head);

    if(node_num == 0){
        return NULL;
    }else if(node_num == 1 || k == 0){
        return first;
    }else{
        while(head != NULL){
            if(head->next == NULL){
                head->next = first;
                break;
            }else{
                head = head->next;
            }
        }        
    }
    
    int Type;
    if(k%node_num == 0){
        Type = node_num;
    }else{
        Type = k%node_num;
    }

    for(int i=0;i<node_num-Type;i++){
        first = first->next;
    }
    struct ListNode* delete = first;
    while(1){
        if(first == delete->next){
            delete->next = NULL;
            break;
        }
        delete = delete->next;
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
        printf("%d %p\n",P->val,P);
        P = P->next;
        }        
    }
    puts("");
}

int main(){
    struct ListNode *l1;
    int num1[]={1,2,3,4,5};

    l1 = create_Linklist(num1,sizeof(num1)/sizeof(num1[0]));

    l1 = rotateRight(l1,2);

    print_list(l1);

    system("pause");
}