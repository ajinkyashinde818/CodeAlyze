#include <stdio.h>
#define SIZE 32767

int main(void) {
    int i = 0;
    int x[SIZE] = {0};
    for(i = 0; i < SIZE; i++) {
        scanf("%d", &x[i]);
    }
    for(i = 0; i < SIZE; i++) {
        if(x[i] == 0) return 0;
        else {
            printf("Case %d: %d\n", i+1, x[i]);
        }
    }
    return 0;
}
