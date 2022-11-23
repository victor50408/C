#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct{
    int data;
}element;
element stack[MAX_SIZE];
element queue[5];
int top = -1;
//------------------ stack -----------------------
void add(int *top,element item){
    if(*top >= MAX_SIZE){
        printf("FULL\n");
        return ;
    }
    stack[++*top] = item;
}

element delete(int *top){
    if(*top < 0){
        printf("EMPTY\n");
        return ;
    }
    return stack[*top--];
}
//------------------- queue  --------------------------
int front = 0;
int real = 0;

void reset_real(int *real){
    *real = *real-1;
    if(*real < 0) *real = 5;
}


void addq(int *real,element item){
    int t;
    t = (*real+1)%6; 
    if(t == front){
        printf("FULL");
        return ;
    }
    *real = t;
    queue[*real] = item;
}

element remove(int *front,int real){
    if(*front == real){
        printf("EMPTY\n");
        return ;
    }
    *front = (*front+1)%6;
    return queue[*front];
}



int main(){
    
    system("pause");
}






