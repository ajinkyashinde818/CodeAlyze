#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n, k, tall, max=0;
    scanf("%d %d", &n, &k);
    
    for (int i=0; i<n; ++i) {
        scanf("%d", &tall);
        if (tall >= k) {
            ++max;
        }
    }
    
    printf("%d", max);
}
