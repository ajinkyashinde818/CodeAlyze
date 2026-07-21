#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long int ll;
int main(){
	ll c;
	int n;
	ll x[100000];
	ll v[100000];
	ll migi[100000];
	ll hidari[100000];
	scanf("%d%lld",&n,&c);
	for(int i=0;i<n;i++) scanf("%lld%lld",x+i,v+i);
	ll sum = 0;
	for(int i=0;i<n;i++){
		sum += v[i];
		migi[i] = sum - x[i];
	}
	sum = 0;
	for(int i=n-1;i>=0;i--){
		sum += v[i];
		hidari[i] = sum - c + x[i];
	}
	ll ans = 0;
	for(int i=0;i<n;i++) ans = max(ans,migi[i]);
	for(int i=0;i<n;i++) ans = max(ans,hidari[i]);
	ll mimi[100000];
	ll hihi[100000];
	for(int i=0;i<n;i++){
		if(i==0) mimi[i] = migi[i] - x[i];
		else mimi[i] = max(migi[i]-x[i],mimi[i-1]);
	}
	for(int i=n-1;i>=0;i--){
		if(i==n-1) hihi[i] = hidari[i];
		else hihi[i] = max(hidari[i],hidari[i+1]);
	}
	for(int i=0;i<n-1;i++) ans = max(ans,mimi[i]+hihi[i+1]);

	for(int i=n-1;i>=0;i--){
		if(i==n-1) hihi[i] = hidari[i] - c + x[i];
		else hihi[i] = max(hidari[i]-c+x[i],hihi[i+1]);
	}
	for(int i=0;i<n;i++){
		if(i==0) mimi[i] = migi[i];
		else mimi[i] = max(migi[i],migi[i-1]);
	}
	for(int i=0;i<n-1;i++) ans = max(ans,mimi[i]+hihi[i+1]);
	printf("%lld\n",ans);
}
