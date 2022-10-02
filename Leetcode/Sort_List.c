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
        current->next = NULL;
        current->val = NUM[i];


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


struct ListNode* sortList(struct ListNode* head){
    struct ListNode* NODE = NULL;
    struct ListNode* output = NULL;
    struct ListNode* previous = NULL;
    struct ListNode* current = NULL;
    struct ListNode* origin_node = NULL;
    struct ListNode* Min_node = NULL;

    if(head == NULL) return NULL;

    int Min;
    int needSWAP = 0;
    //--------------- Bubble Sort ------------------
    while(head != NULL){
        origin_node = head;
        Min = head->val;
        current = head->next;
        while(current != NULL){
            if(Min > current->val){
                Min = current->val;
                Min_node = current;
                needSWAP = 1;
            }
            current = current->next;
        }

        if(needSWAP == 1){
            SWAP(&head,origin_node,Min_node);
            needSWAP = 0;
        }
        
        NODE = (struct ListNode*)malloc(sizeof(struct ListNode));
        NODE->val = Min;
        NODE->next = NULL;

        if(previous == NULL){
            output = NODE;
        }else{
            previous->next = NODE;
        }
        previous = NODE;
        head = head->next;
    }
    return output;
}





int main(){
    struct ListNode *l1;
    int num1[]={4,2,1,3};

    l1 = create_Linklist(num1,sizeof(num1)/sizeof(num1[0]));

    l1 = sortList(l1);

    print_list(l1);

    system("pause");
}