#include <stdio.h>
#include <stdlib.h>
#define MAX_COL 6
#define NumberOfValue 8

struct array{
	int row;
	int col;
	int val;
};
typedef struct array term;

void fast_transpose(term a[],term b[]){
	int row_terms[MAX_COL]; //row_terms[0] = 2(meaning in a's col "numbers of zero" is 2)
	int starting_pos[NumberOfValue]; //the index to put in b's row
	int num_cols = a[0].col;
	int num_terms = a[0].val;
	b[0].col = a[0].row;
	b[0].row = a[0].col;
	b[0].val = a[0].val;

	if(num_terms > 0){
		for(int i=0;i<num_cols;i++){ //inital
			row_terms[i] = 0;
		}	
		for(int i=1;i<=num_terms;i++){ //scanning a's col and add the numbers of "0" in index [0] "1" in index [1]
			row_terms[a[i].col]++;	   
		}	
		starting_pos[0] = 1; // 1 is begin because [0][0] is define
		for(int i=1;i<num_cols;i++){
			starting_pos[i] = row_terms[i-1] + starting_pos[i-1]; //starting_pos[0] = 1 is put "0" in b[index=1]
		}
		for(int i=1;i<=num_terms;i++){
			int index = starting_pos[a[i].col]++;
			b[index].col = a[i].row;
			b[index].row = a[i].col;
			b[index].val = a[i].val;
		}
	}
}

void Attach(term *d,int index,int row,int col,int val){
	d[index].row = row;
	d[index].col = col;
	d[index].val = val;
}

void PRINT(term d[]){
	for(int i=0;i<=NumberOfValue;i++){
		printf("[%d] %d %d %d\n",i,d[i].row,d[i].col,d[i].val);
	}
	puts("");
}

int main()
{
	term a[NumberOfValue+1],b[NumberOfValue];
	a[0].row = MAX_COL ;
	a[0].col = MAX_COL ;
	a[0].val = NumberOfValue;
	Attach(a,1,0,0,15);
	Attach(a,2,0,3,22);
	Attach(a,3,0,5,-15);
	Attach(a,4,1,1,11);
	Attach(a,5,1,2,3);
	Attach(a,6,2,3,-6);
	Attach(a,7,4,0,91);
	Attach(a,8,5,2,28);

	PRINT(a);
	fast_transpose(a,b);
	PRINT(b);
	system("pause");
	
}
