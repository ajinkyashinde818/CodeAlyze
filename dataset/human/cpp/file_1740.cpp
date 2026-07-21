#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int ans[1005][1005];
int con[10005];
int main()
{
    int N,M,i,j,k,ok=0,now=1;
    scanf("%d",&N);
    for(i=1;i*(i+1)/2<=N;i++)
    {
        if(i*(i+1)/2==N)
        {
            printf("Yes\n");
            printf("%d\n",i+1);
            ok=1;
            for(j=1;j<=i+1;j++)
            {
                for(k=j+1;k<=i+1;k++)
                {
                    ans[j][con[j]++]=now;
                    ans[k][con[k]++]=now;
                    now++;
                }
            }

            for(j=1;j<=i+1;j++)
            {
                printf("%d ",i);
                for(k=0;k<i;k++) printf("%d ",ans[j][k]);
                printf("\n");
            }
        }
    }
    if(!ok) printf("No\n");
    return 0;
}
