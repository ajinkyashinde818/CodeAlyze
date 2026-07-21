#include <stdio.h>
int main(void)
{
    int R,G,B,N,i,j,ans=0;
    scanf("%d%d%d%d", &R,&G,&B,&N);
    for(i=0; R*i<=N; i++)
    {
        for(j=0; G*j<=N-R*i; j++)
        {
            if((N-R*i-G*j)%B==0) ans++;
        }
    }
    printf("%d", ans);

    return 0;
}
