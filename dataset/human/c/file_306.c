#include <stdio.h>
#define abs(x)  ((x)>=0 ? (x) : ((x)*-1))


int main(){

    int N, K, i, j;
    scanf("%d", &N);

    long long int B[N], ans = 0;
    for (i=0; i<N; i++){
        scanf("%lld", &B[i]);
    }

    long long int min=10000000000, min_sequence;
    int mi_num=0;
    for (i=0; i<N; i++){
        if (abs(B[i]) < min){
            min = abs(B[i]);
            min_sequence = i;
        }
        if (B[i] < 0) mi_num++;
    }

    if (mi_num%2 == 0){
        for (i=0; i<N; i++){
            ans += abs(B[i]);
        }
    }else{
        for (i=0; i<N; i++){
            ans += abs(B[i]);
        }
        ans -= 2*abs(B[min_sequence]);
    }
 

    printf("%lld", ans);

    return 0;
}
