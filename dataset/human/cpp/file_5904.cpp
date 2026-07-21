#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const int N=2e5+5; 
ll n,C,x[N],v[N],pv[N],sv[N];
priority_queue<ii> q,q2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>C;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>v[i],pv[i]=pv[i-1]+v[i];
	ll val=0;
	for(int i=n;i>=1;i--)
	{
		val+=v[i],sv[i]=val;
		q.push(ii(val-(C-x[i]),n-i+1));
	}
	ll res=0,p=1,mx=0;
	for(int i=0;i<=n;i++)
	{
		ll c1=2ll*x[i];
		if(i==0)
			c1=0;
		//case 1
		while(!q.empty()&&(q.top().second>n-i||C-x[n-q.top().second+1]<=x[i]))
			q.pop();
		if(!q.empty())
			res=max(res,pv[i]-c1+max(0ll,q.top().first));	
		//case 2
		while(p<=n-i&&C-x[n-p+1]<=x[i])
			q2.push(ii(sv[n-p+1]-2ll*(C-x[n-p+1]),p)),p++;
		while(!q2.empty()&&(q2.top().second>n-i))
			q2.pop();			
		if(!q2.empty())
			res=max(res,pv[i]-x[i]+max(0ll,q2.top().first));
		res=max(res,pv[i]-x[i]);		
	//	cout<<i<<' '<<res<<'\n';
	}
	cout<<res<<'\n';
	return 0;
}
