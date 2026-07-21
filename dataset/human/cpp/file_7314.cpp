#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const ll INF=100000000000000LL;

int main() {
	int n;
	ll a[200001];
	cin>>n;
	ll t=0;
	for(int i=0;i<n;++i){
		cin>>a[i];
		t+=a[i];
	}
	ll t1=0;
	ll r=INF;
	for(int i=0;i<n-1;++i){
		t-=a[i];
		t1+=a[i];
		r=min(r,abs(t1-t));
	}
	cout<<r<<endl;
		return 0;
}
