#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

long long p,c,n,x[100005],v[100005],ma,s,g,d;

int main()
{
	n=read();
	cin>>c;
	for(int i=1; i<=n; ++i){
		cin>>x[i];
		v[i]=read();
	}
	for(int i=1; i<=n; ++i)s+=v[i];
	ma=max(0ll,s-x[n]);
	
	d=s-x[n];
	for(int i=n; i; --i){
		d+=x[i]-x[i-1]-v[i];
		p+=v[i];
		g=max(g,p-(c-x[i]));
		ma=max(ma,d);
		ma=max(ma,d-x[i-1]+g);
	}
	
	for(int i=1; i<=n; ++i)x[i]=c-x[i]; 
	
	s=0;for(int i=1; i<=n; ++i)s+=v[i];
	ma=max(ma,s-x[1]);
	
	d=s-x[1]; p=0; g=0;
	for(int i=1; i<=n; ++i){  //<
		d+=x[i]-x[i+1]-v[i];
		p+=v[i];
		g=max(g,p-(c-x[i]));
		ma=max(ma,d);
		ma=max(ma,d-x[i+1]+g);
	}
	
	printf("%lld\n",ma);
	
}
