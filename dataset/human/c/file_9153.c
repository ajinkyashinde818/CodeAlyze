#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    int N,K;
    int a[100000+10];
    int ans = 0;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        if (a[i] >= K) {
            ans++;
        }
    }
    printf("%d\n",ans);

}
