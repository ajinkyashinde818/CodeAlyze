#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll abs(ll x){
	if(x<0) return (-1)*x;
	return x;
}

int main()
{	
	int n,i,x,zer=0,pos=0,neg=0; cin>>n;
	vector<ll> a(n);
	for(i=0;i<n;i++){
		cin>>x; 
		if(x>0) pos++;
		if(x<0) neg++;
		if(x == 0) zer++;
		a[i] = abs(x);
	}

	sort(a.begin(), a.end());
	bool rempos = false;
	if(neg%2 == 0) rempos=true;
	else{
		if(zer>0) rempos=true;
		else rempos=false;
	}

	ll ans=0;
	for(i=1;i<n;i++) ans += a[i];

	if(rempos) ans += a[0];
	else ans -= a[0];

	cout<<ans;	
}
