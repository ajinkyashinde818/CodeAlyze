#include <bits/stdc++.h>
using namespace std;
using ll= long long;

int main() {
	ll N;
	cin >> N;
	vector<ll> a(N);
	for(int i=0;i<N;i++){
		cin >> a.at(i);
	}
	// if(N==2){
		// cout<<llabs(a.at(0)-a.at(1))<<endl;
	// }
	// else{
		vector<ll> sum(N);
		sum.at(0)=a.at(0);
		for(int i=1;i<N;i++){
			sum.at(i)=sum.at(i-1)+a.at(i);
		}
		ll asum=sum.at(N-1);
		ll ans=10000000000000000;
		for(int i=0;i<N-1;i++){
			// cout<<"sum:"<<sum.at(i)<<endl;
			ll K=llabs(asum-sum.at(i)-sum.at(i));
			if(K<ans){
				ans=K;
			}
			
		}
		// cout<<"sum;"<<sum.at(N-1)<<endl;
		// cout<<"asum;"<<asum<<endl;
		cout<<ans<<endl;
	// }
}
