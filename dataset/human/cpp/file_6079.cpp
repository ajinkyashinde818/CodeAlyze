#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll h1[120000],h2[120000],h3[120000],h4[120000],x[120000],y[120000];
ll m,s,t;
 
int main()
{
    int i, n;
	scanf("%d%lld",&n,&m);
	for (i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&y[i]);
	for (i=1,t=0;i<=n;i++)
		t=t+y[i],h1[i]=max(h1[i-1],t-x[i]),h2[i]=max(h2[i-1],t-2*x[i]);
	for (i=n,t=0;i>0;i--)
		t=t+y[i],h3[i]=max(h3[i+1],t-(m-x[i])),h4[i]=max(h4[i+1],t-2*(m-x[i]));
	for (i=0;i<=n;i++)
		s=max(s,max(h1[i]+h4[i+1],h2[i]+h3[i+1]));
	return !printf("%lld\n",s);
}
