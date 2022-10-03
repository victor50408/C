#include <stdio.h>
#include <stdlib.h>

struct Students {
    char *name;
    int id;
};

typedef struct Students STU;

int main(){

    STU VICTOR; // or can write : struct Students VICTOR

    VICTOR.name = "Victor";
    VICTOR.id = 410500218;
    printf("VICTOR:\n");
    printf("%s %d\n\n",VICTOR.name,VICTOR.id);
    

    STU VICTOR_Copy = VICTOR;
    printf("VICTOR_Copy:\n");
    printf("%s %d\n\n",VICTOR_Copy.name,VICTOR_Copy.id);


    STU ANDY = {"Andy",777};
    printf("ANDY:\n");
    printf("%s %d\n\n",ANDY.name,ANDY.id);

    system("pause");
}