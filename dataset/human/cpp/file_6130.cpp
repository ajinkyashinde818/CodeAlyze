#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll x[N] , v[N];
pair<ll,ll> maxRightAnswer[N],maxLeftAnswer[N];
int main(){
 	ll n, c;
 	cin>>n>>c;
 	ll ans = 0;
 	for(int i = 0 ; i < n ;++i)
 		cin>>x[i]>>v[i];
 	pair<ll,ll> ans1 , ans2;
 	ll k = 0,k2=0;
 	for(int i = 0 ; i < n ;++i){
 		k+=v[i];
 		k2+=v[n-i-1];
 		// cout<<k<<" "<<k2<<endl;
 		if(ans1.first<k - x[i])
 			ans1 = {k-x[i],x[i]};
 		if(ans2.first<k2 - (c-x[n-i-1]))
 			ans2 = {k2 - (c - x[n-i-1]) , c - x[n-i-1]};
 		 // cout<<ans1.first<<" "<<k<<"\n"<<k2<<" "<<ans2.first<<endl<<endl;
 		maxLeftAnswer[i]=ans1;
 		maxRightAnswer[n-i-1]=ans2;
 		ans=max(ans,max(ans1.first , ans2.first));
 	}
 	// cout<<ans<<endl;
 	for(int i = 0 ; i < n ;++i){
 		pair<ll,ll> r, l = maxLeftAnswer[i];
 		r = maxRightAnswer[i+1];
 		ans = max(ans ,l.first+r.first - min(l.second , r.second));
 	}
 	cout<<ans<<endl;
}
