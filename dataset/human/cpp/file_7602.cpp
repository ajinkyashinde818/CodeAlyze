#include"bits/stdc++.h"
using namespace std;
int main(){
	int n;
	vector<long long> z;
	cin>>n;
	for(int i=0;i!=n;++i){
		long long temp;
		cin>>temp;
		z.push_back(temp);
	}
	long long x,y=0,ans;
	for(int i=0;i!=n;++i)
		y+=z[i];
	x=z[0],y-=z[0];
	ans=abs(x-y);
	for(int i=1;i!=n-1;++i){
		x+=z[i];
		y-=z[i];
		ans=min(ans,abs(x-y));
	}
	cout<<ans;
}
