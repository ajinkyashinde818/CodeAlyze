#include <stdio.h>
int main(void){
    int b, i, ans;
    long a;
    int h[100000];
    scanf("%ld%d", &a, &b);
    for(i = 0; i < a;  i++){
        scanf("%d", &h[i]);
    }
    ans = 0;
    for(i = 0; i < a; i++){
        if(h[i] >= b){
            ans = ans + 1;
        }
    }
    printf("%d", ans);
}
