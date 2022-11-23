#include <stdio.h>
#include <stdlib.h>
#include "com.h"

void push(element item){
    //put element into top
	if(top >= MAX_STACK_SIZE-1){
        fprintf(stderr, "stack is full");
        exit(EXIT_FAILURE);
        }
    stack[++top]=item;
}

element pop()
{ // return element and delete element at top
    if (top == -1){
        fprintf(stderr, "stack is empty");
        exit(EXIT_FAILURE);
    }
	return stack[top--];
}
