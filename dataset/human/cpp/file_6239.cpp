#include<bits/stdc++.h>
using namespace std;

const int Maxn=1e5+5;
int n;
long long c,x[Maxn],v[Maxn];

int main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>v[i];
	}
	x[n+1]=c;
	long long ans=0,sum=0;
	for(int i=1;i<=n;i++){
		sum+=v[i]-(x[i]-x[i-1]);
		ans=max(ans,sum);
	}
	sum=0;
	for(int i=n;i>=1;i--){
		sum+=v[i]-(x[i+1]-x[i]);
		ans=max(ans,sum);
	}
	
	long long l[Maxn]={0},r[Maxn]={0};
	sum=0;
	long long maxv=0;
	for(int i=1;i<=n;i++){
		sum+=v[i]-2*(x[i]-x[i-1]);
		maxv=max(maxv,sum);
		l[i]=maxv;
	}
	sum=0; maxv=0;
	for(int i=n;i>=1;i--){
		sum+=v[i]-(x[i+1]-x[i]);
		maxv=max(maxv,sum);
		r[i]=maxv;
	}
	for(int i=2;i<=n;i++){
		ans=max(ans,l[i-1]+r[i]);
	}
	
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	sum=0; maxv=0;
	for(int i=1;i<=n;i++){
		sum+=v[i]-(x[i]-x[i-1]);
		maxv=max(maxv,sum);
		l[i]=maxv;
	}
	sum=0; maxv=0;
	for(int i=n;i>=1;i--){
		sum+=v[i]-2*(x[i+1]-x[i]);
		maxv=max(maxv,sum);
		r[i]=maxv;
	}
	for(int i=2;i<=n;i++){
		ans=max(ans,l[i-1]+r[i]);
	}
	cout<<ans;
}
