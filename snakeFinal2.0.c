#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define ROW 25 //地圖寬
#define COL 35 //地圖長
#define first_snake_head_x 10 //最初蛇頭x:10
#define first_snake_head_y 10 //最初蛇頭y:10
int border[ROW][COL]={0}; //整個遊戲地圖
int snake_lenght=3; //一開始蛇的長度
int snake_head_x,snake_head_y; //蛇頭座標
int delete_snake_x[1000],delete_snake_y[1000]; //紀錄蛇頭所有的位置(x,y)，方便刪除
int fruit_x,fruit_y; //果實座標
int barrier_x[100],barrier_y[100]; //障礙物x,y
int diffcult; //難度
char mode[50];


void choose_diffcult(); //選擇難度
void init_map(); //初始化地圖
void produce(int x,int y,int fruit); //生成蛇體和果實
void game_run(); //主要遊戲運行
void print_map();//印出地圖
void delete_snake(int x,int y,int position,int run); //刪除蛇尾
int lose(int x,int y,int counter,int fruit_num);//判斷輸，碰到邊界



/*****************/
int main(){
    srand(time(NULL));
    choose_diffcult(); //選擇難度
    init_map(); //初始化地圖
    game_run(); //主要遊戲運行
    system("pause");
}

/*****************/

void choose_diffcult(){ //選擇難度
    while(1){
        printf("Please select difficulty\n");
        printf("1. Easy\n");
        printf("2. Middle\n");
        printf("3. Difficulty\n");
        scanf("%d",&diffcult);
        if(diffcult==1){
            diffcult=10;
            strcpy(mode,"Easy");
            break;
        }else if(diffcult==2){
            diffcult=30;
            strcpy(mode,"Middle");
            break;
        }else if(diffcult==3){
            diffcult=50;
            strcpy(mode,"Difficulty");
            break;
        }  
    }

    
}


void init_map(){ //初始化地圖
    int i,j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            border[i][j]=32;    // ascii:32= space
        }
    }
    for(i=0;i<ROW;i++){
        border[i][0]=124;
        border[i][COL-1]=124;  // ascii:124= |
    }
    for(j=0;j<COL;j++){
        border[0][j]=95;
        border[ROW-1][j]=95;   // ascii:95= _
    }
    snake_head_x=first_snake_head_x;    //蛇頭設定(10,10)
    snake_head_y=first_snake_head_y;
    produce(snake_head_x,snake_head_y,0); //生成蛇頭，座標(10,10)
    produce(snake_head_x-1,snake_head_y,0); //生成蛇頭，座標(9,10)
    produce(snake_head_x-2,snake_head_y,0); //生成蛇頭，座標(8,10)
    produce(0,0,2); //生成障礙物
    produce(0,0,1); //生成果實，(0,0,1)的0,0沒有意義，別管他，因為是隨機生成
    for(i=0;i<3;i++){
        delete_snake_x[i]=first_snake_head_x-2+i; //將最初蛇體(8,10)(9,10)(10,10)紀錄到陣列中
        delete_snake_y[i]=first_snake_head_y;
        }

}

void print_map(){ //印出地圖
    int i,j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            printf("%c",border[i][j]);  //先用int矩陣接著用char的形式表現(不然只用int呈現不好看，都是數字)，int與char是互通的，可以查ascii
        }
        printf("\n");
    }
}


void produce(int x,int y,int fruit){ //生成蛇體和果實
    int i;
    if(fruit==0){
        border[y][x]=48;    // 0
    }else if(fruit==1){/*
        do  //果實避免重複的設定
        {
            fruit_x=rand()%COL;
            fruit_y=rand()%ROW;


        } while (border[fruit_y][fruit_x]!=32); //如果生成位置不是space(32)，重新生成*/
        while (1)
        {
            int key=0;
            fruit_x=rand()%COL;
            fruit_y=rand()%ROW;
            //printf("%d",1);            
            if(border[fruit_y+1][fruit_x]!=32){
                key++;
            }
            if(border[fruit_y-1][fruit_x]!=32){
                key++;
            }            
            if(border[fruit_y][fruit_x+1]!=32){
                key++;
            }
            if(border[fruit_y][fruit_x-1]!=32){
                key++;
            }
            if(key<3 && border[fruit_y][fruit_x]==32){
                border[fruit_y][fruit_x]=36;     //$
                break;
            }

        }

    }else if(fruit==-1){    //刪除
        border[y][x]=32;    //變成space(32)空白

    }else if(fruit==2){
        for(i=0;i<diffcult;i++){
            do  //果實避免重複的設定
            {
                barrier_x[i]=rand()%COL;
                barrier_y[i]=rand()%ROW;
            } while (border[barrier_y[i]][barrier_x[i]]!=32); //如果生成位置不是X(32)，重新生成
            border[barrier_y[i]][barrier_x[i]]=88;  
        }
  
    }

}

void game_run(){ //主要遊戲運行
    int direction=3;    //預設向右
    int result,speed,i=0,position=0,counter=0,fruit_num=0;
    while(1){
        if(GetAsyncKeyState(VK_UP) && direction!=1){        // direction!=1 代表向下時，不能按向上鍵
            direction=0;//UP
        }else if(GetAsyncKeyState(VK_DOWN) && direction!=0){// direction!=0 代表向上時，不能按向下鍵
            direction=1;//DOWN
        }else if(GetAsyncKeyState(VK_LEFT) && direction!=3){// direction!=3 代表向右時，不能按向左鍵
            direction=2;//LEFT
        }else if(GetAsyncKeyState(VK_RIGHT) && direction!=2){// direction!=2 代表向左時，不能按向右鍵
            direction=3;//RIGHT
        }
    switch (direction){
    case 0: //UP
        snake_head_y--;
        break;
    case 1: //DOWN
         snake_head_y++;
        break;
    case 2: //LEFT
         snake_head_x--;
        break;
    case 3: //RIGHT
         snake_head_x++;
        break;
    }
    produce(snake_head_x,snake_head_y,0); //生成新的蛇頭座標
    delete_snake_x[counter+3]=snake_head_x; //紀錄每個蛇頭x位置
    delete_snake_y[counter+3]=snake_head_y; //紀錄每個蛇頭y位置

    if((snake_head_x==fruit_x) && (snake_head_y==fruit_y)){ //吃到果實(少吃一次)
        position--; //防止跳過
        produce(0,0,1); //重生果實，(0,0,1)的0,0沒有意義，別管他
        fruit_num++;
    }else{
        produce(delete_snake_x[position],delete_snake_y[position],-1); //刪除蛇身
    }
    print_map();
    printf("\n");
    result=lose(snake_head_x,snake_head_y,counter,fruit_num);
    if(result==1){
        system("cls"); //清屏
        printf("YOU LOSE!!!\n");
        printf("====================\n");
        printf("Your Score: %d\n",fruit_num);

        break;
    }
    counter++;
    position++;
    speed=350-fruit_num*10;
    printf("Game mode:\t%s\n",mode);
    printf("snake_length:\t%d\n",3+fruit_num);
    if(speed>0){
        printf("Speed level:\t%d\n",fruit_num);
        Sleep(speed); //暫停speed毫秒
    }else{
        printf("Speed level:\tMAX\n");
    }

    system("cls"); //清屏
    }
}


int lose(int x,int y,int counter,int fruit_num){
    int i;
    if(x==0 || x==COL-1 || y==0 || y==ROW-1){ //撞牆輸掉
        return 1;
    }else{ //撞身體輸掉
        for(i=0;i<fruit_num+3;i++){ //用迴圈來抓身體的座標，如果蛇頭等於身體座標的話，輸!
            if(x==delete_snake_x[counter+3-i-1] && y==delete_snake_y[counter+3-i-1]){ //從頭依照身體長度(fruit_num+3)，去抓身體的座標
                return 1;
            }
        }
    }
    for(i=0;i<diffcult;i++){ //撞到障礙物輸掉
        if(x==barrier_x[i] && y==barrier_y[i]){
            return 1;
        }
    }

}

