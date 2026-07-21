#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    char N[3];

    scanf("%s", N);

    if(N[0] == '9' || N[1] == '9'){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}
