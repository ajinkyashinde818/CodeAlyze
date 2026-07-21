#include <stdio.h>
int main(void){
    int n, k, h[1000000], i, a=0;
    
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++) scanf("%d",&h[i]);
    
    for(i=0;i<n;i++){
        if(h[i]>=k) a++;
    }
    printf("%d\n",a);
    return 0;
}
