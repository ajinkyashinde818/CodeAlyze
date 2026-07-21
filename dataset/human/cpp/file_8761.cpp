#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<string>
#include <iomanip>
#include<deque>
#include<queue>
#include<stack>
#include<set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef int itn;
const ll LINF = 1e18;
const int INF = 1e8;

//マクロ定義
#define vvint(vec,n,m,l) vector<vector<int>> vec(n, vector<int>(m,l));	// lで初期化
#define vvll(vec,n,m,l) vector<vector<ll>> vec(n,vector<ll>(m,l));
#define vint vector<int>
#define pint pair<int,int>
#define rep(i,a) for(int i=0;i<(a);i++)
#define all(x) (x).begin(),(x).end()
#define debug system("pause")				//デバッグ用
#define ret return 0

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	vector<string> b(m);
	rep(i, n)
	{
		cin >> a[i];
	}
	rep(i, m)
	{
		cin >> b[i];
	}
	bool ans = false;
	
	for (int i = 0; i < n - m + 1; i++)
	{
		for (int j = 0; j < n - m + 1; j++)
		{
			if (a[i][j] == b[0][0])
			{
				for (int k = 0; k < m; k++)
				{
					for (int l = 0; l < m; l++)
					{
						if (a[i + k][j + l] == b[k][l])
						{
							ans = true;
							continue;
						}
						ans = false;
						break;
					}
					if (!ans)
					{
						break;
					}
				}
				if (ans)
				{
					cout << "Yes" << endl;
					ret;
				}
			}
		}
	}


	cout << "No" << endl;
	return 0;
}
