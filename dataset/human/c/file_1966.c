#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void){
    
    int n;
    int a[99]={};
    int b[99]={};
    int c[99]={};
    int ans=0;
    int tmp=0;
    
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++){
        
        scanf("%d", &a[i]);
        
    }
    
    for(int i=1; i<=n; i++){
        
        scanf("%d", &b[i]);
        ans += b[i];
        // printf("+%d\n", b[i]); // debug
        
    }
    
    for(int i=1; i<n; i++){
        
        scanf("%d", &c[i]);
        
    }
    
    for(int i=1; i<n; i++){
        
        tmp = a[i+1] - a[i];
        
        if(tmp==1){
            
            tmp = a[i];
            ans += c[tmp];
            // printf("++%d\n", c[tmp]); // debug
            
        }
        
    }
    
    printf("%d", ans);
    
    return 0;
    
}
