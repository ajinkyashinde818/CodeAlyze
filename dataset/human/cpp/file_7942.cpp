#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef long long int lli;
const long long int MaxN=300005;
const lli mod=1e9+7;
#define fst first
#define snd second
#define mp make_pair
const float pi=3.1415926535897932384626433832795028;
	lli mcd(lli a,lli b){
		if(a==0)return b;
		return mcd(b%a,a);
	}
	lli arr[MaxN];
	lli pre[MaxN];
	void solve(){
		lli N,i,j,p,q,res=1e16,s;
		cin>>N;		
		for(i=1;i<=N;i++){
			cin>>arr[i];
		}
		//sort(arr+1,arr+N+1);
		for(i=1;i<=N;i++){
			pre[i]=pre[i-1]+arr[i];
		}
		s=arr[N];
		for(i=N-1;i>=1;i--){
			res=min(res,abs(pre[i]-s));
			s+=arr[i];
		}
		cout<<res;
	}
int main(){
	cin.tie(0),ios_base::sync_with_stdio(0);
	lli i,t;
	t=1;
	for(i=1;i<=t;i++){
		solve();
	}
}
