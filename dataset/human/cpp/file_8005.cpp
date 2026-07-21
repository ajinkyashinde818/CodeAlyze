#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int INF = 1000000007;

int main(){
	int n; cin>>n;
	ll a[210000]={0};
	for(int i=0;i<n;i++) cin>>a[i];

	ll x=0,y=0;
	for(int i=0;i<n-1;i++){
		x += a[i];
	}
	y += a[n-1];

	//cout<<x<<" "<<y<<endl;

	if(n==2) cout<< abs(x - y) <<endl;

	else{
		ll mins=abs(x - y), d=0;
		for(int i=n-2;i>=1;i--){
			x -= a[i];
			y += a[i];
			d = abs(x - y);
			mins = min(mins, d);

			//cout<<x<<" "<<y<<endl<<endl;
		}

		cout<< mins <<endl;
	}

	return 0;
}
