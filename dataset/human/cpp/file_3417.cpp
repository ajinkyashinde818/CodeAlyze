/**
 *    viet the nay ko phai bat chuoc tourist
 *    ma la muon noi rang
 *	 doc code ban khac la suc vat khong phai con nguoi
**/


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef pair<ll, pair<ll,ll> > iii;
typedef vector<ll> vi;

const int kn = 2e5 + 1;
const int N = 1e5 + 1;
const ll mod = 1e9 + 7;

//#define x first
//#define y second
#define _it iterator
#define pb push_back
#define f(i,a,b) for(int i=a;i<=b;i++)
#define ff(i,n) for(int i=1;i<=n;i++)
#define ms(val,a) memset(a,val,sizeof(a))
#define _ff(i,n) for(int i=n;i>=1;i--)
#define _f(i,a,b) for(int i=b;i>=a;i--)
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n, a[N], b[N];
ll dp[N][2];

int main() {
	cin >> n;
	ff(i,n) cin >> a[i];
	dp[2][0] = a[1] + a[2]; dp[2][1] = -a[1] - a[2];
	for(int i = 3; i<= n; i++)
	{
		dp[i][0] = max(dp[i-1][1], dp[i-1][0]) + a[i];
		if(i>3) dp[i][1] = max(dp[i-2][0],dp[i-2][1]) + a[i-1]*(-1) + a[i]*(-1);
		else dp[i][1] = -99999999;
		dp[i][1] = max(dp[i][1], dp[i-1][1] - a[i-1]*(-1) +a[i-1] + a[i]*(-1));
		dp[i][1] = max(dp[i][1], dp[i-1][0] - a[i-1] + a[i-1]*(-1) + a[i]*(-1));
		//cout << i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	cout << max(dp[n][1],dp[n][0]);
	
}
