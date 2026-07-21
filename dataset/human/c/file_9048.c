#include <stdio.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int h[100000];
    for(int i=0;i<n;i++) scanf("%d",&h[i]);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(h[i]>=k) ans++;
    }
    printf("%d",ans);
}
