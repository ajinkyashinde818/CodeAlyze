#include <stdio.h>
int main(void){
    int n, min = 2000000000, ans = -1000000000, cur;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cur);
        if(i) {
            if(ans < cur - min) ans = cur - min;
        }
        if(min>cur) min = cur;
    }
    
    printf("%d\n", ans);
    
    return 0;
}
