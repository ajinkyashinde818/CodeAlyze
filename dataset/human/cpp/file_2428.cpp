#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
typedef long long ll;
int INF=1<<29;

int main(){
	ll n,sei=0,hu=0,zero=0;
	cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>0) sei++;
		else if(a[i]<0) hu++;
		else zero++;
		a[i]=abs(a[i]);
	}
	sort(a.begin(),a.end());
	ll sum=accumulate(a.begin(),a.end(),0LL);
	if(hu%2==0 || (hu+zero)%2==0) cout<<sum<<endl;
	else if(hu%2==1) cout<<sum-2*a[0]<<endl;
	return 0;
}
