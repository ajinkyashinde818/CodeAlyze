#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=2e5+5;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,k,ans;
	cin>>n>>k;
	if(n>=10)ans=k;
	else ans=k+(10-n)*100;
	cout<<ans<<endl;
	return 0;
}
