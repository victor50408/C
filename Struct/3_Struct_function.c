#include <stdio.h>
#include <stdlib.h>

struct Students {
    char *name;
    int id;
};

typedef struct Students STU;

void get_name_id(STU input){
    printf("%s %d\n",input.name,input.id);
}

void get_name_id_pointer(STU *input){
    printf("%s %d\n",input->name,input->id);
}


int main(){
    STU VICTOR = {"victor",410500218};
    get_name_id(VICTOR);

    STU *ANDY = &VICTOR;
    ANDY->name = "andy";
    ANDY->id = 777;
    get_name_id_pointer(ANDY);

    system("pause");
}
