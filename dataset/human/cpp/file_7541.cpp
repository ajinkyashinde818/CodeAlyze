#include<bits/stdc++.h>
using namespace std;
long long arr[200005];

int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) cin>>arr[i];
	for(int i=1; i<=n; i++) arr[i]+=arr[i-1];
	long long mn = numeric_limits<long long>::max();
	for(int i=1; i<=n-1; i++){
		mn = min(mn,abs(arr[i]-(arr[n]-arr[i])));
	}
	cout<<mn;
}
