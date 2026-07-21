#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,i,cur=0,ans=0;
	cin >> n;
	vector<long long> a(n);
	for(i=0; i<n; i++){
		cin >> a[i];
		if(a[i]<0){
			cur++; a[i]=-a[i];
		}
	}
	sort(a.begin(),a.end());
	if(cur%2) a[0]=-a[0];
	for(i=0; i<n; i++){
		ans+=a[i];
	}
	cout <<ans;
}
