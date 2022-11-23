#include <stdio.h>
#include <stdlib.h>
#include "com.h"

void readMaze();
void initMark();
void path();

int moveVert[8]={-1,-1,0,1,1,1,0,-1};
int moveHoriz[8]={0,1,1,1,0,-1,-1,-1};


int main(void){
    top=-1;
    readMaze();
    initMark();
    path();
    getchar();
}

void readMaze(){

    FILE *fp;
    fp=fopen("maze.txt","r");
    for(int i=0;i<maze_row;i++){
        for(int j=0;j<maze_col;j++){
            fscanf(fp,"%d",&maze[i][j]);
            printf("%d ",maze[i][j]);
            }
        puts("");
        }
    fclose(fp);


}

void initMark(){

    for(int i=0;i<maze_row;i++)
        for(int j=0;j<maze_col;j++)
            mark[i][j]=0;

}


void path(void){
    //output path
    int i, row, col, nextRow, nextCol, dir, found = 0;   element position;
    mark[1][1] = 1; top = 0;
    stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
    while(top > -1 && !found) {
        position = pop();
        row = position.row;  col = position.col;
        dir = position.dir;
        while (dir < 8 && !found) {
                //moving direction from 0 to 7
            nextRow = row + moveVert[dir];
            nextCol = col + moveHoriz[dir];
            if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
                found = 1;
            else if( !maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
                    mark[nextRow][nextCol]=1;
                    position.row = row; position.col = col;
                    position.dir = ++dir;
                    push(position);
                    row = nextRow; col = nextCol; dir = 0;
            }
            else ++dir;
        }
    }
    if (found) {
        printf("The path is:\n");
        printf("row col\n");
        for(i = 0; i <= top; i++){
                if (i>1 && i%5==0)
                puts("");
            printf("%3d%3d, ",stack[i].row, stack[i].col);

            }
        printf("%3d%3d, ",row,col);
        printf("%3d%3d\n", EXIT_ROW ,EXIT_COL);
    }
    else
        printf("The maze does not have a path\n");
}







