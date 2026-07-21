#include<stdio.h>
int main()
{
    int n,k,all[100005]={0};
    scanf("%d %d",&n,&k);
    int ans=0;
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&all[i]);
        if(all[i]>=k)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
