#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector<ll> a(n);
	ll sum=0;
	for (int i=0; i<n; i++)
		cin>>a[i], sum+=a[i];
	ll pre=a[0], ret=abs(pre-(sum-pre));
	for (int i=1; i<n-1; i++)
		pre+=a[i], ret=min(ret,abs(pre-(sum-pre)));
	cout<<ret<<"\n";
	return 0;
}
