#include<bits/stdc++.h>
using namespace std;
const int inf=1e5+5;
typedef long long ll;
double mx=-123456789;
ll n,m;
vector<double>v;
int main()
{
   cin>>n;
   ll a[n+1];
   ll sum=0;
   ll cnt=0;
   ll mn=123456789125;
   for(ll i=0;i<n;i++){
    cin>>a[i];
    sum+=abs(a[i]);
    if(a[i]<0){
        cnt++;
    }
    mn=min(mn,abs(a[i]));
   }
   //cout<<mn<<endl;
   if(cnt%2==1){
    sum-=2*mn;
   }
   cout<<sum<<endl;
}
