#include <stdio.h>
int main(void){
    int n,i;
    scanf("%d",&n);
    int a[n],b[n],c[n-1];
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++) scanf("%d",&b[i]);
    for(i=0;i<n-1;i++) scanf("%d",&c[i]);
    int sum = b[a[0]-1];
    for(i=1;i<n;i++){
        sum+=b[a[i]-1];
        if(a[i]-1==a[i-1]) sum+=c[a[i-1]-1];
    }
    printf("%d",sum);
    return 0;
}
