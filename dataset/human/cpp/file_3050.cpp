#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <cassert>
#include <utility>
#include <stack>
#include <queue>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef pair<int,int> Pi;
typedef long long int ll;
const int INF=(ll)(1<<30)-1;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a, b)*b;}


int main(){
	int n;
	ll a[100100];
	ll min=INFl;
	ll ans=0;
	int count=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<0)count++;
		ll t=abs(a[i]);
		ans+=t;
		if(t<min)min=t;
	}
	if(count%2==1){
		ans=ans-(2*min);
	}
	cout<<ans<<endl;
	return 0;
}
