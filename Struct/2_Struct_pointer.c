#include <stdio.h>
#include <stdlib.h>

struct Students {
    char *name;
    int id;
};

typedef struct Students STU;

int main(){
    STU VICTOR = {"Victor",410500218};
    STU *ptr = &VICTOR;
    printf("ptr:\n");
    printf("%s %d\n\n",(*ptr).name,(*ptr).id);    


    STU *arrow = &VICTOR;
    arrow->name = "AAA";
    arrow->id = 777;
    printf("arrow:\n");
    printf("%s %d\n\n",arrow->name,arrow->id);  
    printf("%s %d\n\n",VICTOR.name,VICTOR.id); 


    system("pause");
}