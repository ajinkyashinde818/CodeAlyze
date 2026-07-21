#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
typedef long long ll;

int n;
ll a[maxn],x,sum,ans=1000000000000000000ll;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=0;i<n-1;i++){
		x+=a[i];
		ans=min(ans,abs(2*x-sum));
	}
	cout<<ans<<endl;
	return 0;
}
