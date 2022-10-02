#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int S[1000];
int top;

int push(int x){
    top++;
    S[top]=x;
}

int pop(void){
    int top_num;
    top_num = S[top];
    top--;
    return top_num;
}


int main(){

   // char str1[]="(600*30)+9+400/200" "30 600 * 9 + 400 200 / +"

    
    char str[]="5 6 3 * + 2 2 / - 1 +";
    char NumOP[50][50];
    int NUMOP_int[50];
    int OP_location[50];
    int a,b,counter=0,index=0;
    top=-1;

    for(int j=0;j<strlen(str);j++){
        if(str[j]!=' '){
            int c=0;
            for(int k=j;(str[k]!=' ') && (str[k]!='\0');k++){
                NumOP[counter][c]=str[k];
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
/*
    for(int i=0;i<counter;i++){
        printf("%d ",NUMOP_int[i]);
    }
    puts("");
    for(int i=0;i<index;i++){
        printf("%d ",OP_location[i]);
    }
    puts("");*/


    for(int i=0;i<counter;i++){
        int id=0;
        for(int j=0;j<index;j++){
            if(OP_location[j]==i){
                id++;
            }
        }
            if(NUMOP_int[i] == '*' && id != 0){
                a = pop();
                b = pop();
                push(a*b);  
            }else if(NUMOP_int[i] == '/' && id != 0){
                a = pop();
                b = pop();
                push(b/a);   
            }else if(NUMOP_int[i] == '+' && id != 0){
                a = pop();
                b = pop();
                push(a+b);   
            }else if(NUMOP_int[i] == '-' && id != 0){
                a = pop();
                b = pop();
                push(b-a);   
            }else{
                push(NUMOP_int[i]);
                //printf("%d\n",NUMOP_int[i]);
            }        
    }
    printf("%s\n= %d",str,pop()); 

    system("pause");
}