#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tower(int n,char begin,char end,char aux){
    if(n==1){
        printf("Move disk 1 from peg %c to peg %c\n",begin,end);
    }else{
        tower(n-1,begin,aux,end);
        printf("Move disk %d from peg %c to peg %c\n",n,begin,end);
        tower(n-1,aux,end,begin);
    }
}

int main(){
    tower(3,'A','C','B');
    system("pause");
}