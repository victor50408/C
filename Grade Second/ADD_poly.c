#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 1001
#define COMPARE(a,b) ((a)>(b) ? 1:(a)<(b) ? -1:0)

struct polynomial{
    int expon;
    int coef[MAX_DEGREE];
};
typedef struct polynomial poly;

poly Zero(){
    poly d;
    d.expon = 0;
    for(int i=0;i<MAX_DEGREE;i++){
        d.coef[i] = 0;
    }
    return d;
}

int IsZero(poly Z){
    if(Z.expon < 0) return 1;
    else return 0;
}

poly Remove(poly R,int exp){
    int i = exp-1;
    while (!IsZero(R) && i>=0){
        if(R.coef[i]){
            R.expon = i;
            return R;
        }
        i--;
    }
    R.expon = -1;
    return R;
}

poly Attach(poly d,int COEF,int exp){
    d.expon = exp;
    d.coef[exp] = COEF;
    return d;
}


void PRINT(poly d,int max){
    for(int i=max;i>=0;i--){
        if(d.coef[i]) printf("%dX^%d ",d.coef[i],i);
    }
    puts("");
}


int main()
{
    poly a,b,d;
    int sum,max;

    a = Zero();
    b = Zero();
    d = Zero();

    a.expon = 10;
    a.coef[10] = 2;
    //a.coef[5] = 100;
    a.coef[4] = 1;
    a.coef[3] = 10;
    a.coef[2] = 3;
    //a.coef[0] = 1;

    b.expon = 4;
    b.coef[4] = 1;
    b.coef[3] = 10;
    b.coef[2] = 3;
    b.coef[0] = 1;

    PRINT(a,a.expon);
    PRINT(b,b.expon);
    puts("");
//==============================================
    if(a.expon>b.expon) max = a.expon;
    else max = b.expon;

    while(!IsZero(a) && !IsZero(b)){
        switch (COMPARE(a.expon,b.expon))
        {
        case 1: // a > b
            d = Attach(d,a.coef[a.expon],a.expon);
            a = Remove(a,a.expon);
            break;
        
        case 0:
            sum = a.coef[a.expon] + b.coef[b.expon];
            if(sum){
                d = Attach(d,sum,a.expon);
                a = Remove(a,a.expon);
                b = Remove(b,b.expon);                
            }
            break;
        case -1:
            d = Attach(d,b.coef[b.expon],b.expon);
            b = Remove(b,b.expon);
            break;
        }
    }
    for(;a.expon >= 0;a.expon--){
        d = Attach(d,a.coef[a.expon],a.expon);
    }
    for(;b.expon >= 0;b.expon--){
        d = Attach(d,b.coef[b.expon],b.expon);
    }
    PRINT(d,max);
    
    system("pause");
}