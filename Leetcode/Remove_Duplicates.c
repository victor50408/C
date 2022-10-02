#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode Node;

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* current = head;
    int num;
    int reapet = 0;
    int delete[300];
    while(current != NULL){
        num = current->val;
        if(current->next == NULL){
            break;
        }else{
            struct ListNode* P = current->next;
            while(P != NULL){
                if(P->val == num){
                    delete[reapet] = num;
                    reapet++;
                    break;
                }
                P = P->next;
            }
        }
        current = current->next;
    }

    struct ListNode* first = NULL;
    struct ListNode* current1 = head;
    struct ListNode* previous = NULL;

    int id = 0;
    while(current1 != NULL){
        id = 0;
        for(int i=0;i<reapet;i++){
            if(current1->val == delete[i]){
                id = 1;
            }
        }
        if(id != 1){
            if(previous == NULL){
                first = current1;
            }else{
                previous->next = current1;
            }
            previous = current1;
        }
        current1 = current1->next;  
    }

    if(previous == NULL){//{1,1}
        return NULL;
    }else{//for the end
        previous->next = NULL;
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
    int num1[]={1,2,2};

    l1 = create_Linklist(num1,sizeof(num1)/sizeof(num1[0]));
    print_list(l1);
    l1 = deleteDuplicates(l1);
    print_list(l1);

    system("pause");
}