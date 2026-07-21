#include<stdio.h>

#define MAX 10000

int main() {
    int hako[MAX];
    int i=0, j;
    
    while(1) {
        scanf("%d", &hako[i]);
        if (hako[i] == 0) {
            break;
        }
        i++; //カウント
    }
    
    
    for (j=1; j<=i; j++) {
        printf("Case %d: %d\n", j, hako[j-1]);
    }
    
    return 0;
}
