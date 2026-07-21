#include <bits/stdc++.h>

using namespace std;

typedef long long 		ll;
typedef vector<ll> 		vll;
typedef pair<ll,ll> 	pll;
typedef vector<pll> 	vpll;
typedef vector<int> 	vi;
typedef pair<int,int> 	pii;
typedef vector<pii> 	vpii;

#define fi				first
#define se 				second
#define pb 				push_back
#define mp 				make_pair
#define all(v)			v.begin(),v.end()
#define sz(v)			s.size()
#define rep(i,a,b) 		for(int i=a;i<=b;i++)
#define per(i,a,b) 		for(int i=a;i>=b;i--)
#define fill(a,v)		memset(a,v,sizeof(a))
#define tc				int T;cin>>T;while(T--)
#define nl				printf("\n")
#define aya				printf("yaha aya\n")
#define debug(x,y)		printf("%d %d\n",x,y)
#define fast_io			ios_base::sync_with_stdio(false);cin.tie(NULL);
#define grt				greater<int>()

const int mod = 1e9+7;
const int mod2= 1e9+9;

inline int pow_(ll a, int n, int p=mod){
	int r=1;while(n){if(n&1)r=r*a%p;n>>=1;a=a*a%p;}return r;
}

int main(void)
{
	int R,G,B,N;cin>>R>>G>>B>>N;
	int ans = 0;
	rep(i,0,N)
		rep(j,0,N)
		{
			// i*R + j*G
			int rem = N - i*R - j*G;
			if(rem >=0 and rem%B == 0) ans++;
		}
	cout<<ans<<"\n";
}
