#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int maxn=0x7fffff;
long long a[200005];
ll ans=1000000000000000000;
int main(){
	long long n,i,sum=0,x=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(i=0;i<n-1;i++){
		x+=a[i];
		ans=min(ans,abs(2*x-sum));
	}
	cout<<ans;
	return 0;
}
