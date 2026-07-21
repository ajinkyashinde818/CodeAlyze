#include <stdio.h>
#include <string.h>

int main(void){
    char S[3];
    scanf("%s",S);
    char *check[]={"abc","acb","bac","bca","cab","cba"};
    int count = 0;
    for(int i = 0; i < 6;i++){
        if(strcmp(check[i],S)==0){
        printf("Yes\n");
        }else{
            count++;
        }
    }
    if(count == 6) printf("No\n");
    return 0;

}
