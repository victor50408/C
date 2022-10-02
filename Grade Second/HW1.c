#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(a,b,t) ((t)=(a),(a)=(b),(b)=(t))

char skip_enter(){
    char c;
    while(1){
        scanf("%c",&c);
        if(c != '\n' && c != ' ') break;
    }
    return c;
}


void bubble_sort(int arr[],int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len-1;j++){
            if(arr[j+1] < arr[j]){
            int temp;
            SWAP(arr[j],arr[j+1],temp);
            }
        }
    }

}

void print_array(int arr[],int len,int is_random){
    printf("{");
    for(int i=0;i<len;i++){
        if(is_random) arr[i] = rand()%300;

        if(i != len-1) printf("%d,",arr[i]);
        else printf("%d}\n",arr[i]);
    }
}

int iter_binary(int array[],int high,int target){
    int low = 0;
    int middle;
    while(low <= high){
        middle = (low + high)/2;

        if(target == array[middle]){
            return middle;
        }else if(target > array[middle]){
            low = middle + 1;
        }else{
            high = middle - 1;
        }
    }
    return -1;
}

int re_binary(int array[],int high,int low,int target){
    int middle = (low + high)/2;

    if(low > high) return -1;

    if(target == array[middle]){
        return middle;
    }else if(target > array[middle]){
        re_binary(array,high,middle+1,target);
    }else{
        re_binary(array,middle-1,low,target);
    }
    
}

int iter_squential(int array[],int len,int target){
    for(int i=0;i<len;i++){
        if(array[i] == target) return i;
    }
    return -1;
}

int re_squential(int array[],int index,int target){
    if(index < 0) return -1;
    if(array[index] == target) return index;
    else return re_squential(array,index-1,target);
}



int main(){
    int len;
    srand(time(NULL));
    printf("How many numbers you want to generate:");
    scanf("%d",&len);
    int *array = (int *) malloc(sizeof(int)*len);
    printf("The generated numbers are:\n");
    print_array(array,len,1);
    printf("After sorting...\n");
    bubble_sort(array,len);
    print_array(array,len,0);


    char input;
    int is_Q = 0;
    int position,target;
    while(!is_Q){
        printf("plz input number of your choice or press Q to quit\n");
        printf("1. iterative binary search\n");
        printf("2. recursive binary search\n");
        printf("3. iterative sequential search\n");
        printf("4. recursive sequential search\n");
        input = skip_enter();

        switch (input)
        {
        case '1':
            printf("plz input number you want to found\n");
            scanf("%d",&target);
            position = iter_binary(array,len-1,target);
            if(position != -1) printf("%d is at position %d\n",target,position);
            else printf("No Found\n");

            break;
        case '2':
            printf("plz input number you want to found\n");
            scanf("%d",&target);
            position = re_binary(array,len-1,0,target);
            if(position != -1) printf("%d is at position %d\n",target,position);
            else printf("[No Found]\n");

            break;        
        case '3':
            printf("plz input number you want to found\n");
            scanf("%d",&target);
            position = iter_squential(array,len,target);
            if(position != -1) printf("%d is at position %d\n",target,position);
            else printf("[No Found]\n");   

            break;
        case '4':
            printf("plz input number you want to found\n");
            scanf("%d",&target);
            position = re_squential(array,len-1,target);
            if(position != -1) printf("%d is at position %d\n",target,position);
            else printf("[No Found]\n");      

            break;
        case 'Q':
        case 'q':
            printf("[Exit]\n");
            is_Q = 1;
            break;
        default:
            printf("[Input Error]\n");
            break;
        }
        puts("");
    }

    system("pause");
}