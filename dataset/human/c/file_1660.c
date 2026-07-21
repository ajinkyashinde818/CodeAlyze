#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[30];
    int b[30];
    int c[30];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    for(int i=0;i<n-1;i++) scanf("%d",&c[i]);

    int  ans=0;
    ans+=b[a[0]-1];
    for(int i=1;i<n;i++)
    {
        ans+=b[a[i]-1];
        if(a[i]==a[i-1]+1)
        {
            ans+=c[a[i-1]-1];
        }
    }
    printf("%d\n",ans);
}
