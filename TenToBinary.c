#include <stdio.h>
#include <stdlib.h>

int i=0;
int* binary(int num){
    int* binary_array=malloc(100 * sizeof(int));
    while (num!=0){
        binary_array[i]=num%2;
        num=num/2;
        i++;
    }
    return binary_array;
}


int main(){
    int num;
    scanf("%d",&num);
    int* binary_array = binary(num);
    
    for(int k=i-1;k>=0;k--){
        printf("%d",*(binary_array+k));
    }

    free(binary_array);

    system("pause");
}

