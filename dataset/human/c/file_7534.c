#include <stdio.h>
int main() {
    int i = 0, count = 0, data[10000];
    
    while(1) {
        scanf("%d", &data[i]);
        
        if (data[i] == 0) break;
        
        i++;
    }
    
    count = i;
    
    for (i = 0; i < count; i++) {
        printf("Case %d: %d\n", i+1, data[i]);
    }
    return 0;
}
