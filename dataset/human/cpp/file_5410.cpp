#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const double PI = 4*atan(1);
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;
const string YES = "Possible";
const string NO = "Impossible";
#define pb push_back
#define mp make_pair


int N, R;

void solve()
{
	if(N >=10) cout << R << '\n';
	else{
		cout << R + 100*(10-N) << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> R;
	solve();
	return 0;
}
