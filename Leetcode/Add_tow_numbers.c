#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode Node;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum = 0,carry=0,i=0;
    struct ListNode *head = NULL;
    struct ListNode *previous = NULL;

    while(l1 != NULL && l2 != NULL){
        struct ListNode *current = (struct ListNode *)malloc(sizeof(struct ListNode));//create a node
        current->next = NULL;
        sum = l1->val+l2->val;

        if(sum+carry > 9){//need to carry
            current->val = (sum+carry)%10;
            carry = (sum+carry)/10;
        }else{
            current->val = sum+carry;
            carry = 0;
        }
        l1 = l1->next;
        l2 = l2->next;
        if(i==0){
            head = current;
        }else{
            previous->next = current;
        }
        previous = current;
        i++;
    }
    if(l1 != NULL){//if l1 is not finished 
        while (l1 != NULL){//continue plus
            struct ListNode *current = (struct ListNode *)malloc(sizeof(struct ListNode));
            current->next = NULL;
            sum = l1->val;   

            if(sum+carry > 9){
                current->val = (sum+carry)%10;
                carry = (sum+carry)/10;
            }else{
                current->val = sum+carry;
                carry = 0;
            }
            l1 = l1->next;
            previous->next = current;
            previous = current;        
        }
        
    }else if (l2 != NULL){//if l2 is not finished 
        while (l2 != NULL){//continue plus
            struct ListNode *current = (struct ListNode *)malloc(sizeof(struct ListNode));
            current->next = NULL;
            sum = l2->val;   
            if(sum+carry > 9){
                current->val = (sum+carry)%10;
                carry = (sum+carry)/10;
            }else{
                current->val = sum+carry;
                carry = 0;
            }
            l2 = l2->next;
            previous->next = current;
            previous = current;        
        }        
    }
    if(carry > 0 && (l1 == NULL && l2 == NULL)){//if l1 l2 are finished but forgot to carry
        struct ListNode *current = (struct ListNode *)malloc(sizeof(struct ListNode));
        current->next = NULL; 
        current->val = carry;

        previous->next = current;       
    }    


    return head;
}


Node *create_Linklist(int NUM[],int len){
    Node *head = NULL;
    Node *current = NULL; //node
    Node *p = NULL; //previous(前一次)
    
    for(int i=0;i<len;i++){
        current = (Node *)malloc(sizeof(Node)); //create a node
        current->val = NUM[i];
        current->next = NULL;

        if(i == 0){
            head = current;
        }else{
            p->next = current; //connect previous node to current node
        }
        p = current; //record current node (it will be the previous node from the next state)
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
    struct ListNode *l1,*l2,*l3;
    int num1[]={9,9,9,9,9,9,9};
    int num2[]={9,9,9,9};
    l1 = create_Linklist(num1,7);
    print_list(l1);
    l2 = create_Linklist(num2,4);
    print_list(l2);

    l3 = addTwoNumbers(l1,l2);
    print_list(l3);

    system("pause");
}