#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN=(int)2e5+10;
ll a[MAXN],sum;
int main()
{
	int n;
	scanf("%d",&n);
	ll sum=0,ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
		ans+=abs(a[i]);
	}
	ll  step=0;
	for(int i=1;i<n;i++){
		step+=a[i];
		ans=min(ans,abs(sum-2*step));
	}
	cout<<ans<<endl;
	return 0;
}
