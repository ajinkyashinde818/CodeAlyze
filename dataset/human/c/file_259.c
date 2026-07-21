#include <stdlib.h>
#include <stdio.h>
int compare(const void *a,const void *b){
    if(*(int *)a>*(int *)b)return 1;
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],cnt=0,i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]<0)cnt++;
    }long long ans=0;
    for(i=0;i<n;i++){
        a[i]=abs(a[i]);
        ans+=a[i];
    }
    
    if(cnt%2==1){
        qsort(a,n,sizeof(int),compare);
        ans-=2*a[0];
    }
    printf("%lld",ans);
    return 0;
}
