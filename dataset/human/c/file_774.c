#include<stdio.h>
#include<string.h>
int main()
{
    int p[20],c[20],ok[20];
    int D,G;
    int Gnow,numnow,ans,i,j,k;
    ans=1e9;
    scanf("%d%d",&D,&G);
    for(i=1;i<=D;i++)
    {
        scanf("%d%d",&p[i],&c[i]);
    }
    for(i=0;i<(1<<D);i++)
    {
        Gnow=0;numnow=0;
        int temp=i;
        for(j=1;j<=D;j++)
        {
            if(temp%2==1)ok[j]=1;
            else ok[j]=0;
            temp=temp>>1;
            //printf("%d",ok[j]);
        }
        //printf("\n");
        for(j=1;j<=D;j++)
        {
            if(ok[j]==1)
            {
                Gnow+=c[j]+p[j]*100*j;
                numnow+=p[j];
            }
        }
        bool flag=true;
        for(j=D;j>=1;j--)
        {
            if(Gnow>=G)break;
            if(ok[j]==1)continue;
            for(k=1;k<=p[j];k++)
            {
                Gnow+=100*j;
                numnow++;
                if(Gnow>=G){flag=false;break;}
            }
            if(!flag)break;
        }
        if(Gnow>=G && numnow<ans)ans=numnow;
    }
    printf("%d\n",ans);
    return 0;
}
