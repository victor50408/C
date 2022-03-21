#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char a[20];
    scanf("%s",a);
    int length=strlen(a)+1;
    int m[20]={0};
    int counter=0;
    
    for(int i=0;i<length;i++){
        for(int n=1;n<length-1;n++){
            if(a[i]==a[i+n]){
                m[i+n]=i+n;
                counter++;
            }
        }
    }
    char new_a[length-counter];
    int c=0;
    for(int i=0;i<length;i++){
        new_a[0]=a[0];
        if(i==m[i] && i>0){
            c++;
        }else{
            new_a[i-c]=a[i];
        }
    }
    new_a[length-counter]='\0';
 
    for(int i=0;i<strlen(new_a);i++){
        printf("%c\n",new_a[i]);
    }

    system("pause");
}