#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mx=1e5+10;
ll ans;

int main()
{
	int n;
	scanf("%d",&n);
	int t=1e7,c=0,x;
	
	for (int i=1;i<=n;++i){
		scanf("%d",&x);
		if(x<0){
			++c;
			x=abs(x);
		}
		t=min(t,x);
		ans+=x;
	}
	printf("%lld\n",c&1?ans-(t<<1):ans);
	
}
