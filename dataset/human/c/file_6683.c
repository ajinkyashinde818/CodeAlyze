#include <stdio.h>
#include <stdlib.h>

int main(void){
    int N;
    int max;
    int min;
    int diff;
    int i,j;
    int *ip;
    scanf("%d", &N);
    ip = (int *)malloc(N * sizeof(int));
    for(i = 0 ; i < N; i++){
        scanf("%d", &ip[i]);
    }
    max = ip[1]-ip[0];
    min = ip[0];
    for(i = 1 ; i < N; i++) {
        diff  = ip[i] - min;
        if( diff > max)
            max = diff;

        if(min > ip[i])
            min = ip[i];
    }
    printf("%d\n",max);
    return 0;
}
