#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n; cin>>n;
	vector<int> a(n);
	int sgn=0;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		if(a[i]<0)
			sgn=(sgn+1)%2;
		a[i]=abs(a[i]);
	}
	ll ret=0;
	for (int i=0; i<n; i++)
		ret+=a[i];
	sort(a.begin(),a.end());
	if(sgn)
		ret-=2*a[0];
	cout<<ret<<"\n";
	return 0;
}
