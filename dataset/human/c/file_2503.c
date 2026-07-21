#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    char moji[10] = {};
    scanf("%s", &moji);
    if((moji[0] != moji[1])&&(moji[1]!=moji[2])&&(moji[2]!=moji[0])){
        printf("Yes");
    }else{
        printf("No");
    }

    return 0;
}

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}
