#include <stdio.h>
#include <stdlib.h>

int re(int row,int col){
    if(col==row || col==0 || row<=0){
        return 1;
    }else{
        return re(row-1,col)+re(row-1,col-1);
    }
}



int main(){
    
    int m,n;
    printf("enter the number: m n(n<=m)\n");
    scanf("%d %d",&m,&n);
    printf("X^%d coefficient value: %d\n",n,re(m,n));



    system("pause");
    return 0;
}