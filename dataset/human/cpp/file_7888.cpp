#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
typedef long long int ll;

using namespace std;
int main(){
	ll n,on=0,tw=0,ma=100000000000;
	cin >> n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
		cin >> a[i];
		tw += a[i];
	}
	for(ll i=0;i<n-1;i++){
		on += a[i];
		tw -= a[i];
		ma = min(ma,abs(on - tw));
	}
		
	cout << ma << endl;

}
