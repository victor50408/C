#include <stdio.h>
#include <stdlib.h>

int* delete(int a[],int len,int element[],int element_len){
    int *new = malloc(sizeof(int) * len);
    int repeat=0,counter=0;

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

    return new;
}


int main(){
    int id,ANS=0;
    int a[]={0,1,2,3,4,5,6,7,8,9};
    int b[]={4,7,2,9,6,0,8,1,5,3};
    int group[10][10];

    for(int i=0;i<10;i++){
        if(b[0]==a[i]){
            id=i;
            group[0][0]=a[0];
            group[0][1]=b[0];
        }
    }
    int k=0,j=2;
    int *new_a,*new_b;
    while (1){
        if(ANS==0){
            while (1){
                if(b[id]==a[0]){
                    ANS++;
                    break;
                }
                if(b[id]==a[k]){
                    group[ANS][j]=b[id];
                    id=k;
                    k=0;
                    j++;
                }
                k++; 
            }
            new_a = delete(a,sizeof(a)/sizeof(a[0]),group[0],sizeof(group[0])/sizeof(group[0][0]));
            new_b = delete(b,sizeof(b)/sizeof(a[0]),group[0],sizeof(group[0])/sizeof(group[0][0]));
        }else{
            k=0;
            while (1){
                if(new_b[id]==new_a[0]){
                    ANS++;
                    break;
                }
                if(new_b[id]==new_a[k]){
                    group[ANS][j]=new_b[id];
                    id=k;
                    k=0;
                    j++;
                }
                k++; 
            }
            new_a = delete(new_a,10,group[ANS],sizeof(group[ANS])/sizeof(group[ANS][0]));
            new_b = delete(new_b,10,group[ANS],sizeof(group[ANS])/sizeof(group[ANS][0]));
        }
   
    }
    
    for(int i=0;i<j;i++){
        printf("%d ",group[i]);
    }
    




    system("pause");
    return 0;
}

