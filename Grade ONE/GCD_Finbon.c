#include <stdio.h>
#include <stdlib.h>

int gcd_re(int m,int n){

    if(m%n == 0 ){
        return n;
    }else{
        gcd_re(n,m%n);
    }
}

int gcd(int m,int n){
    for(int i=n;i>0;i--){
        if(m%i==0 && n%i==0){
            return i;
        }
    }
}

int fibon_re(int n){
    if(n==1){
        return 1;
    }else if(n==2){
        return 1;
    }else{
        return fibon_re(n-1)+fibon_re(n-2);
    }
}


int fibon(int n){
    int f[n];
    f[0]=1;
    f[1]=1;
    for(int i=2;i<n;i++){
        f[i]=f[i-1]+f[i-2];
    }
    return f[n-1];
}



int main(){
    int a,b;
    printf("enter two numbers a b(a>b)");
    scanf("%d %d",&a,&b);
    printf("GCD recursive:%d\n",gcd_re(a,b));
    printf("GCD iterative:%d\n",gcd(a,b));

    int num;
    printf("enter a number");
    scanf("%d",&num);
    printf("Fibonacci number recursive:%d\n",fibon_re(num));
    printf("Fibonacci number iterative:%d\n",fibon(num));
    system("pause");
    return 0;
}