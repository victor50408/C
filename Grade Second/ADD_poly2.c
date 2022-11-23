#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 101
#define COMPARE(a,b) ((a)>(b) ? 1:(a)<(b) ? -1:0)

struct polynomial{
    int expon;
    int coef;
};
typedef struct polynomial poly;

poly PUT(poly a[],int coef,int exp,int *pos){   //Attach
    if(*pos >= MAX_DEGREE) exit(1);
    a[*pos].coef = coef;
    a[*pos].expon = exp;
    *pos = *pos + 1;
}

void PRINT(poly a[],int start,int max){
    if(max >= MAX_DEGREE) exit(1);
    for(int i=start;i<=max;i++){
        if(a[i].coef) printf("%dX^%d ",a[i].coef,a[i].expon);
    }
    puts("");
}

int main()
{
    poly temps[MAX_DEGREE];
    int startA = 0;
    int startB = 0;
    int finshinA = 0,finshinB,sum;

    PUT(temps,2,1000,&finshinA);
    PUT(temps,1,0,&finshinA);
    startB = finshinA;
    finshinB = startB;

    PUT(temps,1,4,&finshinB);
    PUT(temps,10,3,&finshinB);
    PUT(temps,3,2,&finshinB);
    PUT(temps,1,0,&finshinB);
    
    int stratNEW = finshinB;
    finshinA = finshinA - 1;
    finshinB = finshinB - 1;

    while(startA <= finshinA && startB <= finshinB){
        switch (COMPARE(temps[startA].expon,temps[startB].expon))
        {
        case 1:
            PUT(temps,temps[startA].coef,temps[startA].expon,&stratNEW);
            startA++;
            break;
        case 0:
            sum = temps[startA].coef + temps[startB].coef;
            PUT(temps,sum,temps[startB].expon,&stratNEW);
            startA++;
            startB++;             
            break;
        case -1:
            PUT(temps,temps[startB].coef,temps[startB].expon,&stratNEW);
            startB++; 
            break;
        }
    }
  
    for(;startA <= finshinA;startA++){
        PUT(temps,temps[startA].coef,temps[startA].expon,&stratNEW);
    }
    for(;startB <= finshinB;startB++){
        PUT(temps,temps[startB].coef,temps[startB].expon,&stratNEW);
    }
    
    PRINT(temps,finshinB+1,stratNEW-1);
    return 0;
}