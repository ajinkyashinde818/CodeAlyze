#include<stdio.h>
#include<stdlib.h>
int main() {
int N, K;
scanf("%d %d", &N, &K);
int i, h, count=0;
for (i=0; i<N; i++) {
        scanf("%d", &h);
        if (h >= K) {
                count++;
        }
}
printf("%d\n", count);
return 0;
}
