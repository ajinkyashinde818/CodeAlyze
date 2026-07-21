#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>

#include <map>
 
using namespace std;
typedef long long ll; 


ll ans,mx,sum,mn=1e10,flag;
int main(){
	ll n;
	cin>>n;
	ll a[n],b[n];
	for(ll i=0; i<n; i++){
		cin>>a[i];
		b[i]=a[i];
		sum += a[i];	
	}
	for(ll i=0; i<n; i++){
		if(i>0) b[i] += b[i-1];
	}
	for(ll i=0; i<n; i++){
		if(i<n-1) {
			flag = sum-b[i];
			
			mn = min(mn,abs(b[i]-flag));
		}
	}
	cout<<mn<<endl;
}
