#include<stdio.h>
int main(void){
    int N, a[100001], i, j, ans;
    scanf("%d", &N);
    for(i = 1; i <= N; i++){
        scanf("%d", &a[i]);
    }
    ans = -1;
    j = 1;
    for(i = 1; i <= N; i++){
        if(a[j] == 2){
            ans = i;
            break;
        }else{
            j = a[j];
        }
    }
    printf("%d\n", ans);
    return 0;
}
