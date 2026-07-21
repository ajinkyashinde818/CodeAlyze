#include<iostream>
#include<functional>
#include<utility>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;
const auto MOD = 1000000007;
const int INF = 1e9;
const long long LINF = 1e18;
#define rep(i,n) for(int i = 0; i < (n);i++)
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;

// index が条件を満たすかどうか vector<>maeに検索したいvectorを入れる keyを超える最小の要素番号を返す
bool isOK(int index, long long key, vector<long long>&mae) {
	if (mae[index] >= key) return true;
	else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(long long key, vector<long long>&mae) {
	int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
	int right = (int)mae.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

	/* どんな二分探索でもここの書き方を変えずにできる！ */
	while (right - left > 1) {
		int mid = left + (right - left) / 2;

		if (isOK(mid, key, mae)) right = mid;
		else left = mid;
	}

	/* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
	return right;
}


long long mod(const long long &a) {
	if (a >= 0)return a % 1000000007;
	return 1000000007 - (-a) % 1000000007;
}
int mod(const int &a) {
	if (a >= 0)return a % 1000000007;
	return 1000000007 - (-a) % 1000000007;
}
bool get(const char a) {//黒なら1　白なら0
	if (a == 'B')return 1;
	else return 0;
}
long long fact(long long a) {
	long long ret = 1;
	for (int i = 1; i <= a; i++)
	{
		ret = mod(ret*i);
	}
	return ret;
}

int main() {
	int n;
	string s;
	cin >>n>> s;
	int state=0;
	VI inout(2*n,0);//1なら出る,0なら入る
	for (int i = 0; i < 2*n; i++)
	{
		if (state < 0) { puts("0");return 0; }
		if ((state + get(s[i])) % 2) {
			inout[i] = 1;state++;continue;
		}
		state--;
	}
	if (state) { puts("0");return 0; }
	ll ans = 1;
	int out = 0;
	for (int i = 0; i < 2*n; i++)
	{
		if (inout[i]) {
			out++;
		}
		else {
			ans = mod(ans*out);
			out--;
		}
	}
	ans = mod(ans*fact(n));
	cout << ans << endl;
}
