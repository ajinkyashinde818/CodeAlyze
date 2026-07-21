#include <bits/stdc++.h>
using namespace std;
long long int jue(long long int aa)
{
    if(aa<0)
    {
        return -1*aa;
    }
    else
    {
        return aa;
    }
}
int main()
{
  int n;
  long long int a[210000];
  long long int s=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
      scanf("%lld",&a[i]);
      s+=a[i];
  }
  long long int s1=0;
  int i;
  long long int minn=999999999999999;
  for( i=0;i<n-1;i++)
  {
     s1+=a[i];
     if(jue(s-2*s1)<minn)
     {
         minn=jue(s-2*s1);
     }
  }
  printf("%lld\n",minn);
    return 0;
}
