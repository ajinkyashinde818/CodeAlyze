#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll a,b,c,n;
    cin>>a>>b>>c>>n;
    ll ans=0;
    for(ll i=0;i<3010;i++)for(ll j=0;j<3010;j++){
	ll rem=n-i*a-j*b;
	if(rem%c==0){
	    rem/=c;
	    if(rem>=0)ans++;
	}
    }
    cout<<ans<<endl;
    return 0;
}
