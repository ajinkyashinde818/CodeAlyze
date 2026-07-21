#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include<vector>

using namespace std;
typedef long long ll;

ll ans,mx,sum,mn=1e18,cnt,flag;

ll b[100000],idx;
int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0; i<n; i++){
		cin>>a[i];
		if(a[i]<=0) b[idx++]=i;
	}
	for(ll i=0; i<n; i++){
		if(a[i]<0){
			bool ok=false;
			for(ll j=0; j<idx; j++){
				if(b[j]>i){
					a[i]=abs(a[i]);
					a[b[j]]=abs(a[b[j]]);
					ok=true;
					break;
				}
			}
			if(ok==false){
				for(ll j=0; j<n; j++){
					if(abs(a[j])<mn){
						flag=j;
						mn=abs(a[j]);
					}
				}
				a[i]=abs(a[i]);
				a[flag] *=-1;
			}
		}
	}
	for(ll i=0; i<n; i++){
		sum+=a[i];
	}
	cout<<sum;
}
