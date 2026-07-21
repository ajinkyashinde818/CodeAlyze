#include <stdio.h>
#include <math.h>

int main(void){
    int n;
    int a[100000+5];
    scanf("%d", &n);
    for(int i=1; i<=n; i++)scanf("%d", &a[i]);
    
    int now=1, cnt=0;
    for(int i=0; i<n; i++){
        if(now==2){
            printf("%d\n", cnt);
            return 0;
        }
        cnt++;
        now=a[now];
    }
    printf("-1\n");
    
    return 0;
}
