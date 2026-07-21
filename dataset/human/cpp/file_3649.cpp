#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int a[200005];
int n,eve=0;
bool zero=false;
ll min(ll a,ll b)
{
    if(a>b)return b;
    else return a;
}
int main()
{
    ll ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0)zero=true;
        if(a[i]<0)eve++;
        ans+=abs(a[i]);
    }
    if(zero==true||eve%2==0){
         cout<<ans<<endl;
    }else{
        ll minm=10000000000;
        for(int i=0;i<n;i++)
        {
            minm=min(abs(a[i]),minm);
        }
        cout<<ans-2*minm<<endl;
    }
    
}
