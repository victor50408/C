#ifndef COM_H_INCLUDED
#define COM_H_INCLUDED

#define MAX_STACK_SIZE 101
#define maze_row 13
#define maze_col 17
#define EXIT_ROW 12
#define EXIT_COL 16

/*typedef struct{
    short int vert;
    short int horiz;

}offsets;*/

typedef struct{
    short int row; 
    short int col;
    short int dir; //direction
}element;

int top;
element stack[MAX_STACK_SIZE];
extern int moveHoriz[8];
extern int moveVert[8];
extern element pop();
extern void push(element );
int mark[maze_row][maze_col];
int maze[maze_row][maze_col];




#endif // COM_H_INCLUDED
