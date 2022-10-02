#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char *str = "I Love You";




void reverse(int n){
    char str[80];
    if(n==1){
        scanf("%s",str);
        printf("%s ",str);
    }else{
        scanf("%s",str);
        reverse(n-1);
        printf("%s%s",str," ");

    }

}




int main(){
    
    reverse(3);
    system("pause");
}