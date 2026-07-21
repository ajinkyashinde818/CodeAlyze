#include <stdio.h>
int main(void)
{
    int N;
    int K;
    int h[100000];
    int i;
    int ans=0;
    
    scanf("%d",&N);
    scanf("%d",&K);
    
    if(N<=100000)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&h[i]);
        }
    }
    
    for(i=0;i<N;i++)
    {
        if(h[i]>=K)
        {
            ans++;
        }
    }
    printf("%d",ans);
    
}
