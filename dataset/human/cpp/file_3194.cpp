#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
ll N[maxn];
int main()
{
	int n;cin>>n;int cnt=0;ll sum=0;ll minn=1e9+1;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&N[i]);sum+=abs(N[i]);
		if(N[i]<0) cnt++;
		minn=min(minn,abs(N[i]));
	}
	if(cnt%2==0) cout<<sum<<endl;
	else cout<<sum-2*minn<<endl;
 }
