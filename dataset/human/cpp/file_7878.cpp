#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int inf = 2e9+5;

int main(){
	int n;
	cin>>n;
	ll arr[n];

	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=1;i<n;i++) arr[i] = arr[i]+arr[i-1];

	ll res = inf;
	for(int i=0;i<n-1;i++){
		res = min(res,abs(arr[i]-(arr[n-1]-arr[i])));
	}
	cout<<res;
}
