#include <iostream>
#include<cmath>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main()
{

    int n;
    while(cin>>n)
    {
  int pan=0;
  int ans=0;
        for(int i=0;i<n;i++)
        {

            cin>>a[i];
            if(a[i]==0)
                pan++;
            if(a[i]<0)
                ans++;
        }
        long long sum=0;
        if(pan==1)
        {
             for(int i=0;i<n;i++)
             {
                 if(a[i]<0)
                    a[i]=-a[i];
                 sum+=a[i];
             }
             cout<<sum<<endl;
             continue;
        }
        if(ans%2==0)
        {
             for(int i=0;i<n;i++)
             {
                 if(a[i]<0)
                    a[i]=-a[i];
                 sum+=a[i];
             }
             cout<<sum<<endl;
             continue;

        }
        int _min=1e9;
        int j=0;
        for(int i=0;i<n;i++)
             {
                 if(fabs(a[i])<_min)
                   {

                    _min=fabs(a[i]);
                    j=i;
                   }
             }
             a[j]=0;
             sum+=-_min;
             for(int i=0;i<n;i++)
             {
                 if(a[i]<0)
                    a[i]=-a[i];
                 sum+=a[i];
             }
             cout<<sum<<endl;

    }
    return 0;
}
