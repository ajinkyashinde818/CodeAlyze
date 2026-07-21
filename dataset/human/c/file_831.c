#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MaxN 55
typedef long long LL;
int a[MaxN];
int b[MaxN];
int f[MaxN][MaxN];
int d[MaxN][MaxN];
int N;
LL my_pow(LL ds,LL cf)
{
    LL sum=1;
    while( cf > 0 )
    {
        if( cf & 1 == 1 )
            sum*=ds;
        ds*=ds;
        cf>>=1;
    }
    return sum;
}
void floyd()
{
    for(int zhan=0;zhan<MaxN;zhan++)
        for(int star=0;star<MaxN;star++)
            for(int end=0;end<MaxN;end++)
                if(d[star][zhan] && d[zhan][end])
                    d[star][end]=1;
}
void copy()
{
    for(int i=0;i<MaxN;i++)
        for(int k=0;k<MaxN;k++)
            d[i][k]=f[i][k];
}
bool check(int x)
{
    copy();
    for(int i=1;i<=x;i++)
        for(int k=i;k<=50;k++)
            d[k][k%i]=1;
    floyd();
    int i;
    for(i=0;i<N;i++)
        if(d[a[i]][b[i]]==0)
            break;
    if(i!=N)
        return false;
    else
        return true;
}
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<N;i++)
        scanf("%d",&b[i]);
    for(int i=0;i<=50;i++)
        for(int k=0;k<=50;k++)
            if(i==k)
                f[i][k]=1;
            else
                f[i][k]=0;
    LL sum=0;
    for(int i=51;i>=1;i--)
    {
        if(!check(i-1))
        {
            if(i==51)
            {
                printf("-1");
                return 0;
            }
            else
            {
                sum+=my_pow(2, i);
                for(int k=i;k<=50;k++)
                    f[k][k%i]=1;
            }
        }
    }
    printf("%lld\n",sum);
    return 0;
}
