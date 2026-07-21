#include<bits/stdc++.h>
using namespace std;
int n;
long long num[200050];
long long sum[200050];
int main() {
	scanf("%d",&n);
	sum[0]=0;
	for(int i=1;i<=n;i++) {
		scanf("%lld",&num[i]);
		sum[i]=sum[i-1]+num[i];
	}
	long long mi=1e18;
	for(int i=1;i<=n-1;i++) {
		mi=min(mi,abs((sum[i]-sum[0])-(sum[n]-sum[i])));
	}
	printf("%lld\n",mi);
	return 0;
}
