#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int MX=100010, inf=2e9;
pli A[MX], B[MX];
int n; ll c;
ll solve(pli R[], pli L[]){
	ll G1[MX]={}, G2[MX]={};
	ll sum=0, moved=0;
	for(int i=1; i<=n; i++){
		sum+=R[i].second, moved=R[i].first;
		ll now=sum-moved;
		G1[i]=now;
	}
	sum=moved=0;
	for(int i=1; i<=n; i++){
		sum+=L[i].second, moved=L[i].first;
		ll now=sum-2*moved;
		G2[i]=now;
	}
	ll mx=0, res=0;
	for(int i=n; i>=1; i--){
		mx=max(mx, G2[n-i]);
		res=max(res, mx+G1[i]);
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>c;
	for(int i=1; i<=n; i++)
		cin>>A[i].first>>A[i].second;
	for(int i=1; i<=n; i++){
		B[i].first=c-A[n-i+1].first;
		B[i].second=A[n-i+1].second;
	}
	cout<<max(solve(A,B), solve(B,A));
	return 0;
}
