#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>

using namespace std;

typedef long long ll;

ll a[200005];
ll sum[200005];

int main(){

	int N;
	scanf("%d",&N);

	int i;

	for(i=0;i<N;i++){
	scanf(" %lld",&a[i]);
	sum[i]=a[i];
	}

	for(i=1;i<N;i++){
	sum[i]+=sum[i-1];
	}

	ll ans=LLONG_MAX;

	for(i=0;i<=N-2;i++){
	ll x=sum[i];
	ll y=sum[N-1]-x;
	ans=min(ans,llabs(x-y));
	}

	printf("%lld\n",ans);

	return 0;
}
