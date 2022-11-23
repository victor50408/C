#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int Stack_RPN[MAX_SIZE],Stack_ANS[MAX_SIZE],Stack_OP[MAX_SIZE];
int top_RPN = -1,top_ANS = -1,top_OP = -1;

int is_Empty(char *flag){ // 1: is Empty  0: not Empty
    if(flag == "RPN"){
        if(top_RPN == -1) return 1;
    }else if (flag == "ANS"){
        if(top_ANS == -1) return 1;
    }else if (flag == "OP"){
        if(top_OP == -1) return 1;
    }
    return 0;
}

int top_val(char *flag){ // return the top value of Stack
    if(flag == "RPN"){
        return Stack_RPN[top_RPN];
    }else if (flag == "ANS"){
        return Stack_ANS[top_ANS];
    }else if (flag == "OP"){
        return Stack_OP[top_OP];
    }
}

void push(char *flag,int x){
    if(flag == "RPN"){
        Stack_RPN[++top_RPN] = x;
    }else if (flag == "ANS"){
        Stack_ANS[++top_ANS] = x;
    }else if (flag == "OP"){
        Stack_OP[++top_OP] = x;
    }
}

int pop(char *flag){
    if(flag == "RPN"){
       return Stack_RPN[top_RPN--];
    }else if (flag == "ANS"){
        return Stack_ANS[top_ANS--];
    }else if (flag == "OP"){
        return Stack_OP[top_OP--];
    }

}

int Order(char s){
    if(s=='(') return 1;
    else if(s=='+') return 2;
    else if(s=='-') return 2;
    else if(s=='*') return 3;
    else if(s=='/') return 3;
    else if(s == '%') return 3;
}


void EqToRPN(char *Eq){ // Equation to Infix
    int pop_val,i=0;
    while(Eq[i] != '\0'){
        switch (Eq[i])
        {
        case '(':
            push("OP",Eq[i]);
            break;
        case ')':
            while(!is_Empty("OP") && (pop_val = pop("OP")) != '('){ // pop until find the '('
                push("RPN",pop_val);
            }
            break;
        case '+':  
        case '-': 
        case '*': 
        case '/': 
        case '%': 
            while(!is_Empty("OP") && Order(Eq[i]) <= Order(top_val("OP"))){ // in Stack_OP: if (input_val's order) <= (top_val's order) then pop all 
                push("RPN",pop("OP"));
            }
            push("OP",Eq[i]);
            break;
        default: // number
            push("RPN",Eq[i]);
            break;
        }
        i++;
    }
    while(!is_Empty("OP")){
        push("RPN",pop("OP")); //put 
    }
    push("RPN",'X');// X is end of Stack
}

int ANS(){ // read data from Stack_RPN[] (https://www.youtube.com/watch?v=bx6Muc9WhuI&ab_channel=LeetCode%E5%8A%9B%E6%89%A3)
    int i=0; 
    int a,b;   
    while(Stack_RPN[i] != 'X'){
        switch (Stack_RPN[i])
        {
        case '+':
            a = pop("ANS");
            b = pop("ANS");
            push("ANS",a+b);
            break;
        case '-':
            a = pop("ANS");
            b = pop("ANS");
            push("ANS",b-a);
            break;
        case '*':
            a = pop("ANS");
            b = pop("ANS");
            push("ANS",a*b);
            break;
        case '/':
            a = pop("ANS");
            b = pop("ANS");
            push("ANS",b/a);
            break;
        case '%':
            a = pop("ANS");
            b = pop("ANS");
            push("ANS",b%a);
            break;     
        default:
            push("ANS",Stack_RPN[i]-'0');
            break;
        }
        i++;
    }
    return pop("ANS");
}

int main(){
    char Equation[MAX_SIZE];
    printf("Equation : ");
    scanf("%s",Equation);
    EqToRPN(Equation);

    printf("Infix : "); 
    for(int i=0;Stack_RPN[i]!='X';i++){
        printf("%c ",Stack_RPN[i]);
    }
    puts("");
    printf("ANS = %d\n",ANS());

    system("pause");
}