#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char get_command(void);
char *delete(char *source, int index, int n);
char *insert(char *source, char *to_insert, int index);
int position(char *source, char *to_find);


int main(){
    char source[100],command;
    char *NEW_Sentence;
    char to_delete[20],to_insert[20],to_find[20];
    int insert_pos,index;
    int quit = 0;
    printf("Enter the source string\n");
    gets(source);
    while(!quit){
        command = get_command();
        switch (command){
        case 'D':
            printf("Delete words>");
            //scanf("%s",to_delete);
            gets(to_delete);
            while(to_delete[0] == '\0' || to_delete[0] == '\n') gets(to_delete);
            index = position(source,to_delete);
            if(index != -1){
                NEW_Sentence = delete(source,index,strlen(to_delete));
                printf("NEW source: %s\n",NEW_Sentence);
            }else{
                printf("No Found\n");
            }
            break;
        case 'I':
            printf("Insert words>");
            //scanf("%s",to_insert);
            gets(to_insert);
            while(to_insert[0] == '\0' || to_insert[0] == '\n') gets(to_insert);
            printf("Insert position>");
            scanf("%d",&insert_pos);
            if(insert_pos>strlen(source)) printf("Insert position is out of range\n");
            else{
                NEW_Sentence = insert(source,to_insert,insert_pos);
                printf("NEW source: %s\n",NEW_Sentence);
                printf("Position of insertion: %d\n",insert_pos);                
            }
            break;
        case 'F':
            printf("Find words>");
            //scanf("%s",to_find);
            gets(to_find);
            while(to_find[0] == '\0' || to_find[0] == '\n') gets(to_find);
            index = position(source,to_find);
            if(index != -1) printf("The words \"%s\" is at position: %d\n",to_find,index);    
            else printf("No Found\n");      
            break;
        case 'Q':
            quit = 1;
            break;        
        default:
            printf("Wrong command input\n");
            break;
        }
    }
    system("pause");
}

char get_command(){
    char command;
    printf("Enter the command D(delete) I(insert) F(find) Q(quit)\n");
    scanf("%c",&command);
    while(command == '\n') scanf("%c",&command);
    return toupper(command);
}

int position(char *source, char *to_find){
    char str[100];
    int found = 0,i;
    int len = strlen(to_find);
    for(i=0;i<strlen(source);i++){
        if(source[i]!=' ' && source[i]==to_find[0]){
            strncpy(str,&source[i],len);
            str[len] = '\0';
            if(strcmp(str,to_find)==0){
                found = 1;
                break;
            }
        }
    }
    if(found){
        return i;
    }else{
        return -1;
    }
}

char *delete(char *source, int index, int n){
    char str[100];
    strncpy(str,source,index);
    strcpy(&str[index],&source[index+n]);
    strcpy(source,str);
    return source;
}

char *insert(char *source, char *to_insert, int index){
    char str[100];
    char str0[100];
    int len = strlen(to_insert);
    strncpy(str0,source,index);
    str0[index]='\0';

    strncpy(str,to_insert,len);
    strcpy(&str[len],&source[index]);

    strcat(str0,str);
    strcpy(source,str0);

    return source;
}