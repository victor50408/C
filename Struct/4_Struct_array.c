#include <stdio.h>
#include <stdlib.h>

struct Students {
    char *name;
    int id;
};

typedef struct Students STU;

void put_name(STU *input, char *name_list[],int len){
    for(int i=0;i<len;i++){
        input[i].name = name_list[i];
    }
}

void put_id(STU *input, int id_list[], int len){
    for(int i=0;i<len;i++){
        input[i].id = id_list[i];
    }
}

int main(){
    char *name_list[3] = {"Victor","Andy","GGG"};
    int id_list[3] = {410500218,777,111};
    STU STRUCT_STU[3];
    put_name(STRUCT_STU,name_list,3);
    put_id(STRUCT_STU,id_list,3);

    for(int i=0;i<3;i++){
        printf("%s %d\n",STRUCT_STU[i].name,STRUCT_STU[i].id);
    }

    system("pause");
}