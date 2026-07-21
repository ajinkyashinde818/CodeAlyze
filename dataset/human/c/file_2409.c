#include <stdio.h>
#include <stdlib.h>
int main(){
    char str[4] ;
    int count[3]={};
    scanf("%s",str);
    for(int m = 0; m<3;m++){
        count[str[m]-'a']++;
    }
    for(int i=0;i<3;i++){
        if(count[i]!=1){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
