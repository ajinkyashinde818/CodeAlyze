#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char s[3];
    scanf("%s",s);
    if(s[0] != s[1] && s[1] != s[2] && s[2] != s[0]){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}
