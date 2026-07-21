#include <stdio.h>
int main(void)
{
    int n,d,x;
    int a[101]={};
    scanf("%d\n%d %d",&n,&d,&x);
    int num=0;
    for(int p=0;p<n;p++)
    {
        scanf("%d",&a[p]);
        int nnn=(d-1)/a[p]+1;
        num+=nnn;
    }
    int ans=num+x;
    printf("%d",ans);
}
