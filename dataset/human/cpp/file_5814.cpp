#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef struct node
{
    LL x,y;
    LL val;
}point;
point num[100006];
LL maxa[100006];
LL maxb[100006];
int main(void)
{
   LL n,c;
   scanf("%lld %lld",&n,&c);
   for(int i = 1;i <= n;i++)
   scanf("%lld %lld",&num[i].x,&num[i].val),num[i].y = c - num[i].x;
   num[0].x = 0;
   num[n+1].x = 0;
   num[0].y = 0;
   num[n+1].y = 0;
   for(int i = 0;i < 100006;i++)
    maxa[i] = 0,maxb[i] = 0;
   maxa[0] = 0,maxb[0] = 0;
   LL maxx = 0;
   for(int i = 1;i <= n;i++)
   {
       maxa[i] = num[i].val - abs(num[i].x - num[i-1].x) + maxa[i-1];
       maxx = max(maxx,maxa[i]);
   }
   for(int i = n;i >= 1;i--)
   {
       maxb[i] = num[i].val - abs(num[i].y - num[i+1].y) + maxb[i+1];

       maxx = max(maxx,maxb[i]);
   }
   LL maxq = 0;
   for(int i = n - 1;i >= 1;i--)
   {
      maxq = max(maxq,maxb[i+1]);
      maxx = max(maxa[i] + maxq - num[i].x,maxx);
      //printf("%lld\n",maxa[i] + maxq - num[i].x);
   }
   maxq = 0;
   for(int i = 2;i <= n;i++)
   {
       maxq = max(maxq,maxa[i-1]);
       maxx = max(maxb[i] + maxq - num[i].y,maxx);
   }
   printf("%lld\n",maxx);
   return 0;
}
