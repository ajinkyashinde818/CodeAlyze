#include <stdio.h>
#include <string.h>

int main(void){
    int n,k,s = 0,a[50],b[50],c[50];
    int i;
    scanf("%d",&n);
    
    for (i = 0; i<n; i++){
        scanf("%d", &a[i]);
    }
    for (i = 0; i<n; i++){
        scanf("%d", &b[i]);
    }
    for (i = 0; i<n-1; i++){
        scanf("%d", &c[i]);
    }
    for (i = 0; i<n; i++){
        k=a[i]-1;
        s=b[k]+s;
        if(a[i]>0){
            if((a[i]-1)==a[i-1]){
                s=s+c[k-1];
            }
        
        }
        
    }
    
    printf("%d",s);
    return 0;
}
