#include <stdio.h>
#include <stdlib.h>

/*============================================
                Reuse Array
==============================================*/

void* delete(int *NEW,int *a,int len,int element[],int element_len,int first){

    int repeat=0,counter=1;
    int *new = NULL;
    new = (int *) realloc(new,sizeof(int) * len); //Create an array(new) to store the array(NEW) that after deleted

    for(int i=first;i<len;i++){ //If first=0: first use ;  first=1: reuse (look at line 22)
        repeat=0;
        for(int j=0;j<element_len;j++){
            if(a[i]==element[j]){
                repeat=1;
            }
        }
        if(repeat==0){
            new[counter]=a[i]; //If function were reused,then a[0](length of array) is not data,so a[i] must be start from 1(i=1)
            counter++;
        }
    }
    new[0]=counter;   // [0] is length of the array 

    NEW=(int *) realloc(NEW,4*counter);

    for(int i=0;i<new[0];i++){
        NEW[i]=new[i];
    }

    free(new);
}


int main(){

    int A[]={1,2,3,4,5,6,7,8};  //A is the first data
    int del0[]={1,2,3}; // the numbers that need to delete
    int *NEW = malloc(4*sizeof(A)/sizeof(A[0]));    //NEW is reusable array 
    for(int i=0;i<sizeof(A)/sizeof(A[0]);i++){
        NEW[i]=A[i];    //copy A's data to NEW
    }

    printf("%d?",sizeof(A)/sizeof(A[0]));
    delete(NEW,NEW,sizeof(A)/sizeof(A[0]),del0,sizeof(del0)/sizeof(del0[0]),0);

    for(int i=0;i<NEW[0];i++){
        if (i==0){
            printf("lenght of array: %d\n",NEW[0]);
            printf("after delete: ");
        }else{
            printf("%d ",NEW[i]);
        }

    }
    //=========================================================

    puts("");
    int del1[]={8,7};
    delete(NEW,NEW,NEW[0],del1,sizeof(del1)/sizeof(del1[0]),1);

    for(int i=0;i<NEW[0];i++){
        if (i==0){
            printf("lenght of array: %d\n",NEW[0]);
            printf("after delete: ");
        }else{
            printf("%d ",NEW[i]);
        }
    }
    //=========================================================

    puts("");
    int del2[]={4};
    delete(NEW,NEW,NEW[0],del2,sizeof(del2)/sizeof(del2[0]),1);

    for(int i=0;i<NEW[0];i++){
        if (i==0){
            printf("lenght of array: %d\n",NEW[0]);
            printf("after delete: ");
        }else{
            printf("%d ",NEW[i]);
        }
    }

    free(NEW);
    system("pause");
    return 0;
}

