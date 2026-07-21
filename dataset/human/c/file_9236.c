#include <stdio.h>

int main(){
    int n, k, sum = 0, i;
    scanf("%d", &n);
    scanf("%d", &k);
    int h[n];
    for(i = 0; i < n; i++){
        scanf("%d", &h[i]);
        if(h[i] >= k){
            sum++;
        }
    }
    printf("%d", sum);
}
