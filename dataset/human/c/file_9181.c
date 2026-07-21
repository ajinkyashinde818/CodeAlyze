#include <stdio.h>
 
int main(void){
    int n,k,i;
    int h[100000];
    int ans=0;
    scanf("%d %d",&n,&k);
    
    for(i=0; i<=n-1; i++){
        scanf("%d ",&h[i]);
    }
    
    for(i=0; i<=n-1; i++){
        if(h[i]>=k) ans+=1;
    }
    
    printf("%d",ans);
   
    return 0;
}
