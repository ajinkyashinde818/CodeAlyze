#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s[200005]={};

int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)
		scanf("%lld",s+i);
	for(int i = 2; i <= n; ++i)
		s[i] += s[i-1];
	ll diff = 1LL<<60;
	for(int sz = 1; sz < n; ++sz)
		diff = min(diff,abs(s[n]-s[sz]-s[sz]));
	printf("%lld\n",diff);
}
