#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){

    int N;

    scanf("%d", &N);

    int a[N+1];

    for(int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
    }

    int b = 1;

    int f = 1;
    int c = 0;

    for(int i = 0; i < N; i++){
        b = a[b];
        c++;
        if(b == 2){
            f = 0;
            break;
        }
    }

    if(f == 0){
        printf("%d\n", c);
    }else{
        printf("-1\n");
    }

    return 0;
}
