#include <stdio.h>
#include <stdlib.h>

int* delete(int a[],int len,int element[],int element_len){
    int *new = malloc(sizeof(int) * len);
    int repeat=0,counter=1;

    for(int i=0;i<len;i++){
        repeat=0;
        for(int j=0;j<element_len;j++){
            if(a[i]==element[j]){
                repeat=1;
            }
        }
        if(repeat==0){
            new[counter]=a[i];
            counter++;
        }
    }
    new[0]=counter;   // [0] is length of the array 

    return new;
}


int main(){
    int a[]={0,1,2,3,4,5};
    int del[]={0,1};

    int *NEW = delete(a,sizeof(a)/sizeof(a[0]),del,sizeof(del)/sizeof(del[0]));

    for(int i=0;i<NEW[0];i++){
        if (i==0){
            printf("lenght of array: %d\n",NEW[0]);
            printf("after delete: ");
        }else{
            printf("%d ",NEW[i]);
        }

    }



    system("pause");
    return 0;
}

