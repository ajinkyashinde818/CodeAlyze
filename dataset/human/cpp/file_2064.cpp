#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<string>
typedef long long ll;
typedef unsigned long long ull;
const ll LINF = 1e18;
const int INF = 1e8;
using namespace std;


//マクロ定義
#define vvint(vec,n,m,l) vector<vector<int>> vec(n, vector<int>(m,l));	// lで初期化
#define vvll(vec,n,m,l) vector<vector<ll>> vec(n,vector<ll>(m,l));
#define vint vector<int>
#define pint pair<int,int>
#define rep(i,a) for(int i=0;i<(a);i++)
#define all(x) (x).begin(),(x).end()		
#define debug system("pause")				//デバッグ用

int euclidean_gcd(int, int);

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<ll> a(n);
	ll ans=0;

	ll ma = 0;
	int signCon[2] = {};

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] >= 0)
		{
			signCon[0]++;
		}
		else
		{
			signCon[1]++;
		}
	}

	vector<ll> b(n);
	for (int i = 0; i < n; i++)
	{
		b[i] = abs(a[i]);
	}

	sort(b.begin(), b.end());

	if (signCon[1] % 2 == 1)
	{
		ans += -1 * b[0];
		for (int i = 1; i < n; i++)
		{
			ans += b[i];
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			ans += b[i];
		}
	}

	cout << ans << endl;


	

}
