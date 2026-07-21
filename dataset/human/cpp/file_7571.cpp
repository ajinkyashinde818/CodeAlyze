#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<cstdio>
using namespace std;
long long s[200005];
int main()
{
   int n;
   while(scanf("%d",&n)==1)
   {
      long long sum=0;
      s[0]=0;
      for(int i=1;i<=n;i++)
      {
         int a;
         scanf("%d",&a);
         sum+=a;
         s[i]=s[i-1]+a;
      }
      long long minn=300000000000000;
      for(int i=1;i<n;i++)
      {
         long long a=abs(sum-s[i]-s[i]);
         if(minn>a)
            minn=a;
      }
      cout<<minn<<endl;
   }
   return 0;
}
