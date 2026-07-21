#include <stdio.h>

int main() {
    int n, min, max=-1e30, tmp;
    scanf("%d", &n);
    scanf("%d", &min);
    
    for(int i=0; i<n-1; i++) {
        scanf("%d", &tmp);
        if(max < tmp-min) max = tmp-min; 
        if(tmp < min) min = tmp;
    }
    
    printf("%d\n", max);
    
    return 0;
}
