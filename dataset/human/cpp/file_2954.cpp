#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const  int maxn=1e5+10;
const int  inf=0x3f3f3f3f;
int a[maxn];
ll ans=0,sum=0;
int main()
{
     int n;
     scanf("%d",&n);
     int  mins=inf;
       int couts=0;
     for(int i=0;i<n;i++)
      {
          scanf("%d",&a[i]);
          sum+=abs(a[i]);
          mins=min(mins,abs(a[i]));
          if(a[i]<=0)
            couts++;
      }
     // cout<<sum<<endl;
    //  cout<<mins<<endl;
       if(couts%2==0)
        cout<<sum<<endl;
        else
        cout<<sum-(ll)mins*2<<endl;
    return 0;
}
