#include <stdio.h>
#include <stdlib.h>
#define MAX_COL 10
#define NumberOfVal 10

struct matrix{
    int row;
    int col;
    int val;
};
typedef struct matrix terms;


void transpose(terms A[],terms B[]){
    B[0].col = A[0].row;
    B[0].row = A[0].col;
    B[0].val = A[0].val;
    int currentB = 1;
    if(A[0].val > 0){
        for(int i=0;i<A[0].col;i++){
            for(int j=1;j<A[0].val;j++){
                if(A[j].col == i){
                    B[currentB].col = A[j].row;
                    B[currentB].row = A[j].col;
                    B[currentB].val = A[j].val;
                    currentB++;
                }
            }
        }
    }
}

void fast_transpose(terms A[],terms B[]){
    int row_terms[MAX_COL];
    int strating_pos[NumberOfVal];
    int col = A[0].col;
    int max = A[0].val;

    B[0].col = A[0].row;
    B[0].row = A[0].col;
    B[0].val = A[0].val; 
    for(int i=0;i<col;i++){
        row_terms[i] = 0;
    }
    for(int i=1;i<=max;i++){
        row_terms[A[i].col]++;
    }
    strating_pos[0] = 1;    
    for(int i=1;i<col;i++){
        strating_pos[i] = row_terms[i-1] + strating_pos[i-1];
    }
    for(int i=1;i<=max;i++){
        int j = strating_pos[A[i].col]++;
        B[j].row = A[j].col;
        B[j].col = A[j].row;
        B[j].val = A[j].val;
    }


}


int main(){

    system("pause");
}


