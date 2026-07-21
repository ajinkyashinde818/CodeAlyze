#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n; cin>>n;
	int abm=1e9,mc=0;
	vector<int>a(n);
	int64_t ans=0;
	for(auto&&i:a){
		cin>>i;
		mc+=(i<0);
		i=abs(i);
		ans+=i;
		abm=min(abm,i);
	}
	cout<<(mc&1?ans-abm*2:ans)<<"\n"s;
}
