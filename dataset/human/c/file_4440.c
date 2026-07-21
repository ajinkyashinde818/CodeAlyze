#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    int N;

    scanf("%d", &N);

    int D[N][2];

    for(int i = 0; i < N; i++){
        scanf("%d%d", &D[i][0], &D[i][1]);
    }

    int f = 0;

    for(int i = 2; i < N; i++){
        if(D[i-2][0] == D[i-2][1] && D[i-1][0] == D[i-1][1] && D[i][0] == D[i][1]){
            f = 1;
            break;
        }
    }

    if(f == 1){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}
