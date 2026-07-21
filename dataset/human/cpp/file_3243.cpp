#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N];

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=1;i+1<=n;i+=2) {
		if (a[i]+a[i+1]>=0) break;
		a[i]=-a[i]; a[i+1]=-a[i+1];
	}
	long long ans=0;
	for (int i=1;i<=n;i++) ans+=a[i];
	cout<<ans<<endl;
	return 0;
}
