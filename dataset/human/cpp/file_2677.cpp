#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[114514],cnt,num;
int main() {
	ll n,mi=1e10;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		num+=abs(a[i]);
		mi=min(abs(a[i]),mi);
		if(a[i]<0)cnt++;
	}
	if(cnt%2)num-=mi*2;
	cout<<num<<endl;
	return 0;
}
