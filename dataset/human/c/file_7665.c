#include <stdio.h>

int main() {
    int i, j;
    int num[10001] = {0};
    
    i = 0;
    while(1) {
        scanf("%d", &num[i]);
        if(num[i] == 0) break;
        i++;
    }
    
    for(j = 0; j < i; j++) {
        printf("Case %d: %d\n", j+1, num[j]);
    }
    return 0;
}
