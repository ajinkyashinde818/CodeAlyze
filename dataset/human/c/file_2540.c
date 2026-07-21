#include <stdio.h>

int main(void){
    char input[8];
    scanf("%s",input);
    //printf("%s",input);
    if(input[0]!=input[1]&&input[1]!=input[2]&&input[2]!=input[0]){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}
