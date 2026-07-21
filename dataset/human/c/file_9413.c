#include <stdio.h>
int main(void){
    int N, D, x, i, cnt = 0;
    int a[10000];
    
    scanf("%d %d %d", &N, &D, &x);
    
    for(i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }
    
    for(i = 0; i < N; i++){
        if(D % a[i] == 0){
            cnt = cnt + (D / a[i]);
            //printf("%d\n", cnt);
        }else{
            cnt = cnt + ((D / a[i])) + 1;
            //printf("%d\n", cnt);
        }
    }
    printf("%d\n", cnt + x);
    
}
