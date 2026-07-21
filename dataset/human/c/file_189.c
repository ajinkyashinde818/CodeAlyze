#include <stdio.h>

int main(void){
    int N, A[100000];
    int nega_num = 0, min_num = 1000000000;
    unsigned long int ans = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &A[i]);
        if(A[i] < 0){
            nega_num++;
            A[i] *= -1;
        }
        if(A[i] < min_num){
            min_num = A[i];
        }
        ans += A[i];
    }
    if(nega_num % 2 == 1){
        ans -= min_num * 2;
    }
    printf("%lu\n", ans);
    return 0;
}
