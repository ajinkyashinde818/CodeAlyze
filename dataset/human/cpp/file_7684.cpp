#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0),ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int64_t>a(n);
	int tmp;
	cin>>tmp;
	a.at(0)=tmp;
	for(int i=1;i<n;++i){
		cin>>tmp;
		a.at(i)=a.at(i-1)+tmp;
	}
	int64_t ans=numeric_limits<int64_t>::max();
	for(int i=0;i<n-1;++i){
		ans=min(ans,abs(a.back()-a.at(i)*2));
	}
	cout<<ans<<"\n"s;
}
