#include <stdio.h>
#define NUM 1000001

int prime[NUM];

void eratosthenes(void) {
    int i, j;
    for(i = 2; i < NUM; i++ ) {
        for(j = 2; j * i < NUM; j++ ) {
            prime[i * j] = 1;
        }
    }
}

int main(void) {
    int i, count, n, ans;
    eratosthenes();
    while(scanf("%d",&n), n != 0 ) {
        count = 0;
        ans = 0;
        for(i = 2; count < n; i++ ) {
            if(!prime[i]) {
                ans += i;
                count++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
