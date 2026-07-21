#include <stdio.h>

#define SET_LIMIT 10000

int main (void) {
    int x = -1;
    int idx = 0;
    int dataSet[10000];
    
    while (1) {
        
        if (x == 0) {
            break;
        }
        
        scanf("%d", &x);
        if (x < 1 || x > 10000) {
            continue;
        }
        
        dataSet[idx++] = x;
    }
    
    dataSet[idx] = '\0';
    
    for (x = 0; x < idx; x++) {
        printf("Case %d: %d\n", x + 1, dataSet[x]);
    }
    
    return 0;
}
