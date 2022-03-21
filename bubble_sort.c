#include <stdio.h>
#include <stdlib.h>

void bubble(int *a,int len){
    for(int i=0;i<len;i++){
        for(int k=0;k<len-1;k++){
            if(*(a+k)>*(a+k+1)){
                int t=*(a+k+1);
                *(a+k+1)=*(a+k);
                *(a+k)=t;
            }            
        }

    }
        
}



int main(){
    int array[]={1,1,6,8,-1,0,-6,-10,5,49,6,2};
    int len=sizeof(array)/sizeof(array[0]);

    bubble(array,len);
    for(int i=0;i<len;i++){
        printf("%d\n",array[i]);
    }

    system("pause");

}