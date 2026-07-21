#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MaxN 100000+1000
typedef long long LL;
LL my_m=0;
LL q_y[MaxN];
LL q_z[MaxN];
LL x[MaxN];
LL v[MaxN];
LL my_max(LL a,LL b)
{
    return a>b ? a:b;
}
int main()
{
    int N;
    LL C;
    scanf("%d %lld",&N,&C);
    for(int i=0;i<N;i++)
        scanf("%lld %lld",&x[i],&v[i]);
    LL sum=0;
    LL my_ma=0;
    for(int i=0;i<N;i++)
    {
        if(i==0)
            sum+=(v[i]-x[i]);
        else
            sum+=(v[i]-(x[i]-x[i-1]));
        my_ma=my_max(my_ma,sum);
        q_y[i]=my_ma;
        my_m=my_max(my_m, my_ma);
//        printf("%lld\n",sum);
    }
 //   printf("\n");
    sum=0;
    my_ma=0;
    for(int i=N-1;i>=0;i--)
    {
        if(i==N-1)
            sum+=(v[i]-(C-x[i]));
        else
            sum+=(v[i]-(x[i+1]-x[i]));
        my_ma=my_max(my_ma, sum);
        q_z[i]=my_ma;
        my_m=my_max(my_m, my_ma);
 //       printf("%lld\n",sum);
    }
    sum=0;
    for(int i=0;i<N-1;i++)
    {
        if(i==0)
            sum+=(v[i]-2*x[i]);
        else
            sum+=(v[i]-2*(x[i]-x[i-1]));
        my_m=my_max(my_m, sum+q_z[i+1]);
    }
    sum=0;
    for(int i=N-1;i>0;i--)
    {
        if(i==N-1)
            sum+=(v[i]-2*(C-x[i]));
        else
            sum+=(v[i]-2*(x[i+1]-x[i]));
        my_m=my_max(my_m, sum+q_y[i-1]);
    }
    printf("%lld\n",my_m);
    return 0;
}
