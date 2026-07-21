#include <stdio.h>
int main(){
    int i,b=0,n,k;
    scanf("%d",&n);
    int a[n];
    scanf("%d",&k);
    for (i=0;i<n;i++){
        scanf("%d",a+i);
        if (a[i]>=k)
            b++;
    }
    printf("%d",b);
    return 0;
}
