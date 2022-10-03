#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Students {
    char *name;
    int id;
};

typedef struct Students STU;

struct Class {
    char *class_No;
    STU students[2];
};

typedef struct Class CLASS;

void put(CLASS *C_input,char *class_no[],char name_list[3][2][2],int id_list[3][2]){
    for(int i=0;i<3;i++){
        C_input[i].class_No = class_no[i];
        for(int j=0;j<2;j++){
            C_input[i].students[j].name = name_list[i][j];
            C_input[i].students[j].id = id_list[i][j];
        }
        
    }
}






int main(){
    char *Class_NO[3] = {"No.1","No.2","No.3"};
    char C_name[3][2][2] = {
        {"A","B"},
        {"C","D"},
        {"E","F"}
    };
    int C_id[3][2] = {{0,1},{2,3},{4,5}};

    CLASS C[3];
    put(C,Class_NO,C_name,C_id);

    for(int i=0;i<3;i++){
        printf("%s\n",C[i].class_No);
        for(int j=0;j<2;j++){
            printf("%s %d  ",C[i].students[j].name,C[i].students[j].id);
        }
        puts("");
    }


    system("pause");
}
