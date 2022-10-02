#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_empty(char *set){
    return (set[0]=='\0');
}

char *get_set(char *set){
    char str[64];
    printf("Enter the set\n");
    scanf("%s",str);
    strncpy(set,&str[1],strlen(str)-2);
    set[strlen(str)-2] = '\0';
    return set;
}

void inside(char *set){
    if(strlen(set)==1) printf(" %c",set[0]);

    else{
        printf(" %c,",set[0]);
        inside(&set[1]);        
    }
}

void print_set(char *set,char *set_name){
    if (set_name==NULL) printf("{");
    else printf("%s: {",set_name);
    inside(set);
    printf(" }");
}


int is_uncorrect_element(char ele){
    if (ele>='0'&& ele<='9') return 0;
    
    else if (ele>='A'&& ele<='Z') return 0;
    
    else if (ele>='a'&& ele<='z') return 0;
    
    else return 1;
}

int is_valid(char *set){
    if(set[0]=='\0') return 1;
    else {
        if(is_uncorrect_element(set[0])) return 0;

        else return is_valid(&set[1]);
    }
}


int is_element(char ele,char *set){
    if(ele == set[0]) return 1;
    
    else if(set[0] == '\0') return 0;
    
    else return (is_element(ele,&set[1]));
}


int is_subset(char *small,char *set){ //small[0.1.2...]分別去對set的每一個元素
    if( is_empty(small) ) return 1;   //若讀到最後都沒有錯 => small是set的子集
    
    else if( is_element(small[0],set) == 0 ) return 0; //只要一找到不同的，回傳false
    
    else is_subset(&small[1],set); //small[0->1]
}

char *set_union(char *result,char *set1,char *set2){
    char temp[20];
    if (is_empty(set1)) strcpy(result,set2); //如果set1為空，union = {set2}

    else if (!is_element(set1[0],set2)){ //如果set1[0]沒有屬於set2
        sprintf(result,"%c%s",set1[0],set_union(temp,&set1[1],set2)); //把set1[0]加到union(result)，往下(set1[n+1])判斷
    }else{ 
        //set[0]屬於set2
        set_union(result,&set1[1],set2); //不做任何動作，往下(set1[n+1])判斷，因為set2中有set1[0]，所以最後印出set2，會順便印出來
    }
    return result;
}


int main(){
    char ele,set_one[64],set_two[64],set_three[64];

/*===================================== element ========================================*/
    printf("=========================== element ==============================\n");
    get_set(set_one);
    while(!is_valid(set_one)){
        printf("set is not vaild\n");
        get_set(set_one);
    }

    print_set(set_one,"Set1");
    puts("");
    printf("Enter the element\n");
    while(is_uncorrect_element(ele=getchar()));
    if(is_element(ele,set_one)){
        printf("%c is element of ",ele);
        print_set(set_one,"Set1");
    }else{
        printf("%c is not element of ",ele);
        print_set(set_one,"Set1");
    }

    puts("");
/*===================================== subset ========================================*/
    printf("=========================== subset ==============================\n");
    get_set(set_one);
    while(!is_valid(set_one)){
        printf("set is not vaild\n");
        get_set(set_one);
    }
    print_set(set_one,"Set1");
    puts("");
    get_set(set_two);
    while(!is_valid(set_two)){
        printf("set is not vaild\n");
        get_set(set_two);
    }
    print_set(set_two,"Set2");
    puts("");


    if(is_subset(set_one,set_two)){
        print_set(set_one,"Set1");
        printf(" is the subset of ");
        print_set(set_two,"Set2");
    }else{
        print_set(set_one,"Set1");
        printf(" is not the subset of ");
        print_set(set_two,"Set2");       
    }
    puts("");
/*===================================== union ========================================*/
    printf("=========================== union ==============================\n");
    get_set(set_one);
    while(!is_valid(set_one)){
        printf("set is not vaild\n");
        get_set(set_one);
    }
    print_set(set_one,"Set1");
    puts("");
    get_set(set_two);
    while(!is_valid(set_two)){
        printf("set is not vaild\n");
        get_set(set_two);
    }
    print_set(set_two,"Set2");
    puts("");


    printf("Set1 Set2 union set :");
    print_set(set_union(set_three,set_one,set_two),NULL);
    puts("");

    system("pause");
}