#include <iostream>
#include <climits>
#include <stack>
#include <queue>
#include <string>
#include <random>
#include <utility>
#include <cmath>
#include <set>
#include <map>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <vector>
 
using namespace std;
typedef long long ll;
 
 
typedef pair<ll,ll> P;
long long int INF = 1e18;
double Pi = 3.141592653589;
const int mod = 1000000007;
// memset(a,0,sizeof(a)); →全部０にする
 
vector<int> G[100005];
std::vector<P> tree[100010];
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
 
ll i,j,k;
ll n,m;
ll c;
ll migi[100005],hidari[100005],migi2[100005],hidari2[100005];
ll x[100005],v[100005];


int main(){
	cin>>n>>c;
	for(i=0;i<n;i++){
		cin>>x[i]>>v[i];
	}
	ll kati=0;
	for(i=0;i<n;i++){
		kati += v[i];
		if(i==0)migi[i]=kati-x[i];
		else migi[i] = max(migi[i-1],kati - x[i]);
		migi2[i] = kati - 2*x[i];
	}
	kati = 0;
	hidari[n]=0;
	for(i=n-1;i>=0;i--){
		kati += v[i];
		hidari[i] = max(kati - (c - x[i]),hidari[i+1]);
		hidari2[i] = kati - 2*(c-x[i]);
	}
	ll ans = 0;
	for(i=0;i<n;i++){
		ans = max(ans,hidari[i]);
		ans = max(ans,migi[i]);
	}
	for(i=0;i<n-1;i++){
		ans = max(ans,migi[i] + hidari2[i+1]);
		ans = max(ans,migi2[i] + hidari[i+1]);
	}
	cout<<ans<<endl;

	
	return 0;
}
