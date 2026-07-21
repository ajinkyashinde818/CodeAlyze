#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>
#include <iomanip>
#include <limits>
#include <chrono>
#include <random>
#include <array>
#include <unordered_map>
#include <functional>
#include <complex>
#include <numeric>
#include <cctype>
#include <map>
#include <set>
#include <cstdlib>
#include <bitset>
#include <tuple>
#include <assert.h>
#include <deque>
#include <utility>
#include <fstream>

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { a = abs(a), b = abs(b); while (b > 0) { tie(a, b) = make_pair(b, a % b); } return a; }
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

constexpr long long INF = 1LL << 60;
constexpr int inf = 1000000007;
//constexpr long long mod = 1000000007LL;
constexpr long long mod = 998244353;
constexpr int MAX = 5000000;

int main()
{

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	vector<int> cnt(n + 1);
	vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
	vector<int> b(n); for (int i = 0; i < n; i++) cin >> b[i], cnt[b[i]]++;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] > n) {
			cout << "No" << endl;
			return 0;
		}
	}

	reverse(b.begin(), b.end());
	int lf = 0;
	int rg = n - 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			if (a[lf] != b[i] and a[i] != b[lf]) {
				swap(b[lf], b[i]);
				lf++;
			}
			else {
				swap(b[i], b[rg]);
				rg--;
			}
		}
	}
	cout << "Yes" << "\n";
	for (int i = 0; i < n; i++) cout << b[i] << " \n"[i + 1 == n];
	return 0;
}
