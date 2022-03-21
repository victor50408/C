#include <stdio.h>
#include <stdlib.h>

void factorization(int num){
    int number[100],repeat[100];
    int repeat_counter,counter=0;
    for(int i=2;i<num;i++){
        if(num%i==0){
            repeat_counter=0;
            while(num%i ==0){
                num=num/i;
                repeat_counter++;
                number[counter]=i;
                repeat[counter]=repeat_counter;
            }
            counter++;
        }
    }

    if(counter==0){
        printf("1*%d",num);
    }else{
        printf("%d",number[0]);
        repeat[0]-=1;   
        for(int i=0;i<counter;i++){
            for(int k=0;k<repeat[i];k++){
                printf("*%d",number[i]);
            }
        }
        if(num!=1){
            printf("*%d",num);  
        }  
    }
}


int main(){
    int num;
    scanf("%d",&num);

    factorization(num);
    system("pause");
}