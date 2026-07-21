#include <stdio.h>

int main(void){
    int n,k;
    scanf("%d %d",&n,&k);
    int h[n];
    int i,cnt=0;
    for(i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    for(i=0;i<n;i++){
        if(h[i]>=k){
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
