#include<stdio.h>
#include<stdlib.h>

int power(int m, int n);

int main(void)
{
    int d,g,p[10],c[10],i,j,comp[1024][10],score,ans=1000,num,jmax;

    scanf("%d %d",&d,&g);
    for ( i = 0; i < d; i++)
    {
        scanf("%d %d",p+i,c+i);
    }

    for ( i = 0; i <= power(2,d)-1; i++)
    {
        for ( j = 0; j < d; j++)
        {
            comp[i][j]=(i%power(2,j+1))/power(2,j);
        }
    }

    for ( i = 0; i <= power(2,d)-1; i++)
    {
        score=0;
        num=0;
        for ( j = 0; j < d; j++)
        {
            if(comp[i][j]==1)
            {
                score+=p[j]*100*(j+1)+c[j];
                num+=p[j];
            }
        }
    
        if(score<g)
        {
            jmax=-1;
            for ( j = 0; j < d; j++)
            {
                if(comp[i][j]==0) jmax=j;
            }
            if(jmax!=-1)
            {
                if(((g-score)+(100*(jmax+1))-1)/(100*(jmax+1))<=p[jmax]-1)
                {
                    num+=((g-score)+(100*(jmax+1))-1)/(100*(jmax+1));
                    if(ans>num) ans=num;
                }
            }
        }
        else if(ans>num) ans=num;
    }

    printf("%d",ans);

    return 0;
}

int power(int m, int n)
{
    int p=1;
    for (int i = 0; i < n; i++)
    {
        p*=m;
    }

    return p;
}
