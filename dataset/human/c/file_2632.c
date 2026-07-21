#include <stdio.h>
#include<string.h>

int main(void){

    char *s1 = "abc";
    char *s2 = "acb";
    char *s3 = "bac";
    char *s4 = "bca";
    char *s5 = "cab";
    char *s6 = "cba";

    char str[8];
    scanf("%s", str);

    if(strcmp(str,s1)==0){
        printf("Yes\n");
    }else if(strcmp(str,s2)==0){
        printf("Yes\n");
    }else if(strcmp(str,s3)==0){
        printf("Yes\n");
    }else if(strcmp(str,s4)==0){
        printf("Yes\n");
    }else if(strcmp(str,s5)==0){
        printf("Yes\n");
    }else if(strcmp(str,s6)==0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}
