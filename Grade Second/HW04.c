#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;

void create_list(int num[],int len,NODE **head){
    NODE *current = NULL;
    NODE *previous = NULL;
    for(int i=0;i<len;i++){
        current = (NODE *)malloc(sizeof(NODE));
        current->val = num[i];
        if(i==0){
            (*head)->right = current;
            current->left = *head;
        }else{
            previous->right = current;
            current->left = previous;
        }
        if(i == len-1){ //if last node
            current->right = *head;
            (*head)->left = current;
        }
        previous = current;
    }
    if(len == 0){
        (*head)->right = NULL;
        (*head)->left = NULL;
    }
}

void insert_node(NODE **head){
    int insert;
    NODE *end_node = (*head)->left;
    NODE *target_node = (NODE *)malloc(sizeof(NODE));
    printf("Enter the number (insert at end of list): ");
    scanf("%d",&insert);
    target_node->val = insert;

    if((*head)->right == NULL){
        (*head)->right = target_node;
        target_node->left = *head;
        target_node->right = *head;
        (*head)->left = target_node;
    }else{
        end_node->right = target_node;
        target_node->left = end_node;

        target_node->right = *head;
        (*head)->left = target_node;  
    }
}

void delete_node(NODE **head){
    int delete;
    NODE *previous = *head;
    NODE *current = (*head)->right;
    printf("Enter the number that need delete: ");
    scanf("%d",&delete);

    while(current != *head){
        if(current->val == delete){
            previous->right = current->right;
            current->right->left = previous;
            free(current);
            return;
        }
        previous = current;
        current = current->right;
    }
    printf("Not Found!\n");
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
    NODE *current = (*head)->right;
    while(current != *head && current != NULL){
        printf("%d ",current->val);
        current = current->right;
    }
    puts("");
}


void ascending_sort(NODE **head){
    int min;
    NODE *current = (*head)->right;
    NODE *current2,*temp = NULL,*t;
    while(current != *head){
        min = current->val;
        t = current;
        current2 = current->right;
        while(current2 != *head){
            if(min > current2->val){
                min = current2->val;
                temp = current2;
            }
            current2 = current2->right;
        }
        current = current->right;
        if(temp != NULL){
            SWAP(&t,&temp);
            temp = NULL;
        }
    }
}

void free_list(NODE **head){
    NODE *c = (*head)->right;
    NODE *temp;
    while(c != *head){
        temp = c;
        c = c->right;
        free(temp);
    }
    free(c);
    free(temp);
}



int main(){
    NODE *head = (NODE *)malloc(sizeof(NODE));
    int len;
    printf("Enter the num of node: ");
    scanf("%d",&len);
    int *a = (int *)malloc(sizeof(int)*len);
    if(len != 0){
        printf("Enter the node's value EX(1 2 3 4): ");
        for(int i=0;i<len;i++){
            scanf("%d",&a[i]);
        }        
    }

    create_list(a,len,&head);
    printf("=============================================\n");
    printf("After create : ");
    print_list(&head);

    insert_node(&head);
    printf("\nAfter insert : ");
    print_list(&head);

    delete_node(&head);
    printf("\nAfter delete : ");
    print_list(&head);

    ascending_sort(&head);
    printf("\nAscending sort : ");
    print_list(&head);

    free_list(&head);
    free(head);
    free(a);

    system("pause");
}