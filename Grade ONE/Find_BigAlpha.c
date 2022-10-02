#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
int find_max(int a[],int n){
    n--;
    if(n==0){
        return a[0];
    }else if(a[n]>find_max(a,n)){
        return a[n];
    }else{
        return find_max(a,n);
    }
}*/


char *find_Big(char *s,char *out){
    char any[100];
    //printf("out: %p any: %p  %c\n",out,any,s[0]);
    if(s[0]=='\0'){
         sprintf(out,"%c",'\0');
         

    }else{
        if(isupper(s[0])){
            sprintf(out,"%c%s",s[0],find_Big(&s[1],any));

        }else{
            find_Big(&s[1],out);

        }
    }
    //printf("%p %s\n",out,out);
    return out;
}


int main(){
    /*
    int len;
    printf("Enter the length of array: ");
    scanf("%d",&len);

    printf("Enter the elements EX:(1 2 3 4 5):\n");
    int a[len];
    for(int i=0;i<len;i++){
        scanf("%d",&a[i]);
    }

    printf("MAX element: %d\n",find_max(a,len));
    */

    char ans[10];
    //printf("ans: %p\n",ans);
    printf("!%s!",find_Big("JoJoOjOO",ans));
    system("pause");
}

