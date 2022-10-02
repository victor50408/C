#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int S_RPN[1000];
int top_RPN=-1;
int top_op=-1,top_num=-1;
char S_op[50][100],S_num[50][100];

int push_RPN(int x);
int pop_RPN(void);
int push(char *s,char *x);
char* pop(char *s);
char top_val(char *s);
int Order(char s);
int isEmpty(char *s);
char *Equation_To_RPN(char *equation,char RPN[]);
int ANS(char RPN[]);
int find_wrong(char *Equation);

/*===============================================*/

int main(){
    char Equation[50];
    char RPN_out[50];


    scanf("%s",Equation);
    if(find_wrong(Equation) == 0){
        Equation_To_RPN(Equation,RPN_out);
        ANS(RPN_out);          
    }else{
        printf("Wrong input\n");
    }

    system("pause");
    return 0;
}

/*===============================================*/

int push_RPN(int x){
    top_RPN++;
    S_RPN[top_RPN]=x;
}

int pop_RPN(void){
    int top_num;
    top_num = S_RPN[top_RPN];
    top_RPN--;
    return top_num;
}


int push(char *s,char *x){
    if(s=="op"){
        top_op++;
        strcpy(S_op[top_op],x);

    }else if (s=="num"){
        top_num++;
        strcpy(S_num[top_num],x);
    }
}

char* pop(char *s){
    if(s=="op"){
        top_op--;
        return S_op[top_op+1];
    }else if (s=="num"){
        top_num--;
        return S_num[top_num+1];
    }
}

char top_val(char *s){
    if(s=="op"){
        return S_op[top_op][0];
    }else if (s=="num"){
        return S_num[top_num][0];
    }    
}

int Order(char s){
    if(s=='(')
        return 1;
    else if(s=='+')
        return 2;
    else if(s=='-')
        return 2;
    else if(s=='*')
        return 3;
    else if(s=='/')
        return 3;    
}

int isEmpty(char *s){
    if(s=="op")
        if(top_op==-1)
            return 1;
        else
            return 0;
    else if(s=="num")
        if(top_num==-1)
            return 1;
        else
            return 0;
}

char *Equation_To_RPN(char *equation,char RPN[]){
    char ss[50][50];
    int a=0;
    printf("Equation: %s\n",equation);
/*======================== Separate numbers and operator ==========================*/
    printf("Separate numbers and operator: ");
    for(int i=0;i<strlen(equation);i++){
        if(equation[i]<'0' || equation[i]>'9'){   
            ss[a][0]=equation[i];
            ss[a][1]='\0';
            printf("%s ",ss[a]);
            a++;
        }else{
            int counter0=0;
            for(int j=i;equation[j]>='0' && equation[j]<='9';j++){
                ss[a][counter0]=equation[j];
                counter0++;
                i=j;
            }   
            ss[a][counter0]='\0';
            printf("%s ",ss[a]);
            a++;
        }
    }    
    puts("");
/*=========================== Equation To RPN ====================================*/
    char *next;
    for(int i=0;i<a;i++){
        switch (ss[i][0]){
        case '(':
            push("op",ss[i]);
            break;
        case ')':
            while(*(next=pop("op")) != '(')
                push("num",next);
            break;
        case '*':
        case '/':
        case '+':
        case '-':
            while(!isEmpty("op") && Order(ss[i][0])<=Order(top_val("op")))
                push("num",pop("op"));
            push("op",ss[i]);
            break;
        default:
            push("num",ss[i]);
            break;
        }       
    }
    
    while(!isEmpty("op"))
        push("num",pop("op"));

    int RPN_index=0;
    int size_num = top_num;
    for(int i=0;i<=size_num;i++){
        if(S_num[i][0]>='0' && S_num[i][0]<='9'){
            int str_len = strlen(S_num[i]);
            for(int j=0;j<str_len;j++){
                RPN[RPN_index]=S_num[i][j];
                RPN_index++;
            }
        }else{
            RPN[RPN_index]=S_num[i][0];
            RPN_index++;
        }
        RPN[RPN_index]=' ';
        RPN_index++;
    }
    RPN[RPN_index]='\0';

}

int ANS(char RPN[]){
    char NumOP[50][50];
    int NUMOP_int[50];
    int OP_location[50];
    int a,b,counter=0,index=0;
    top_RPN=-1;

    for(int j=0;j<strlen(RPN);j++){
        if(RPN[j]!=' '){
            int c=0;
            for(int k=j;(RPN[k]!=' ') && (RPN[k]!='\0');k++){
                NumOP[counter][c]=RPN[k];
                j++;
                c++;
            }
            NumOP[counter][c]='\0';
      
            int num = atoi(NumOP[counter]);
            if(num==0){ //operator
                NUMOP_int[counter]=((int) NumOP[counter][c-1]);
                OP_location[index]=counter;
                index++;
            }else{      //numbers
                NUMOP_int[counter]=num;
            }
            counter++;
        }
    }

    for(int i=0;i<counter;i++){
        int id=0;
        for(int j=0;j<index;j++){
            if(OP_location[j]==i){
                id++;
            }
        }
            if(NUMOP_int[i] == '*' && id != 0){
                a = pop_RPN();
                b = pop_RPN();
                push_RPN(a*b);  
            }else if(NUMOP_int[i] == '/' && id != 0){
                a = pop_RPN();
                b = pop_RPN();
                push_RPN(b/a);   
            }else if(NUMOP_int[i] == '+' && id != 0){
                a = pop_RPN();
                b = pop_RPN();
                push_RPN(a+b);   
            }else if(NUMOP_int[i] == '-' && id != 0){
                a = pop_RPN();
                b = pop_RPN();
                push_RPN(b-a);   
            }else{
                push_RPN(NUMOP_int[i]);
            }        
    }
    printf("RPN: %s\n= %d\n",RPN,pop_RPN()); 
}

int find_wrong(char *Equation){
    int len = strlen(Equation);
    int up_parentheses_num=0,down_parentheses_num=0;
    int operater[] = {'+','-','*','/'};
    for(int i=0;i<len;i++){
        if(Equation[i]<'0' || Equation[i]>'9'){
            if(Equation[i] == '('){
                up_parentheses_num++;
            }else if(Equation[i] == ')'){
                down_parentheses_num++;
            }else{
                int counter = 0;
                for(int j=0;j<4;j++){
                    if(Equation[i] == operater[j]){
                        counter++;
                    }
                }
                if(counter == 0){
                    return 1;
                }
                if(Equation[i+1]<'0' || Equation[i+1]>'9'){
                    printf("!2!\n");
                    return 1;
                }
                if((Equation[i-1]<'0' || Equation[i-1]>'9') && i>0){
                    printf("!3!\n");
                    return 1;
                }
            }
        }
    }
    if(up_parentheses_num != down_parentheses_num){
        return 1;
    }
    return 0;
}