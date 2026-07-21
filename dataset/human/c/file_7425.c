#include <stdio.h>
int main(void){
    int a[10000] = {}, i, j;
    i = 0;
    while(1){
        scanf("%d", &a[i]);
        if(a[i] == 0){
            break;
        }
        i++;
    }
    for(j = 0; j < i; j++){
        printf("Case %d: %d\n", j + 1, a[j]);
    }
    return 0;
}
