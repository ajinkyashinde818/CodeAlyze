#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n],i;
    for(i=0;i<=n-1;i++)scanf("%d",&a[i]);
    int maxp=a[1]-a[0];
    int min=a[0];
    for(i=1;i<=n-1;i++){
        if(maxp<a[i]-min)maxp=a[i]-min;
        if(min>a[i])min=a[i];
    }
    printf("%d\n",maxp);
    
    return 0;
}
