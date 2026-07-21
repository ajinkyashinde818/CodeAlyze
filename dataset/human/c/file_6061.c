#include <stdio.h>

#define N 200000

int main(){
    int n, i, j, tmp, num[N], max=-999999999, a;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    
     for (j = n - 1; j >= 0; j--) {
        if (num[j] < max) continue;
        for (i = j - 1; i >= 0; i--) {
            tmp = num[j] - num[i];
            max = max < tmp ? tmp : max;
        }
    } 
    
    printf("%d\n", max);
    
    return 0;
}
