#include<stdio.h>

int max(int,int);
int min(int,int);

int main(void) {
    int i, n;
    int R[200000];
    
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &R[i]);
    
    int maxv = -2000000000;
    int minv = R[0];

    for(int i = 1; i < n; i++) {
        maxv = max(maxv, R[i] - minv);
        minv = min(minv, R[i]);
    }

    printf("%d\n", maxv);

    return 0;
}

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

int min(int a, int b) {
    if(a < b) return a;
    else return b;
}
