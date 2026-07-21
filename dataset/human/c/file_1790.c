#include <stdio.h>
int main(void) {
    int n, a[100], b[100], c[100], i, d=0;
    
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++) scanf("%d",&b[i]);
    for(i=0;i<n-1;i++) scanf("%d",&c[i]);
    
    for(i=0;i<n;i++){
        d+=b[a[i]-1];
        if(i!=0){
            if(a[i]==a[i-1]+1) d+=c[a[i-1]-1];
        }
    }
    printf("%d\n",d);
    return 0;
}
