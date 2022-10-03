#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Students {
    char *name;
    int grade;
};
typedef struct Students STU;

struct Classes {
    char *class_name;
    STU STUDENTS[20];
};
typedef struct Classes CLASS;

void print_struct(CLASS *C_input,int class_num,int students_num[]){

}




int main(){
    int i=0;
    int students_num[20],stu_grade,sum=0,total_num=0;;
    char class_name[10],stu_name[10];
    CLASS C[20];
    while(1){
        printf("Enter the class[%d] name (press Q to quit)\n",i);
        scanf("%s",class_name);
        if(strcmp(class_name,"Q")==0 || strcmp(class_name,"q")==0){
            break;
        }
        //strcpy(C[i].class_name,class_name);
        C[i].class_name = class_name;
        system("cls");
        printf("How many students in class[%d] %s: ",i,C[i].class_name);
        scanf("%d",&students_num[i]);
        total_num = total_num + students_num[i];
        printf("  Name  Grade\n");
        for(int j=0;j<students_num[i];j++){
            printf("%d ",j+1);
            scanf("%s %d",stu_name,&stu_grade);
            sum = sum + stu_grade;
            C[i].STUDENTS[j].name = stu_name;
            C[i].STUDENTS[j].grade = stu_grade;
            //printf("%s %d\n",C[i].STUDENTS[j].name,C[i].STUDENTS[j].grade);
        }
        system("cls");
        i++;
    }
    system("cls");
    printf("AVG: %.2f",(float)sum/total_num);


    system("pause");
}