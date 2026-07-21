#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
#include <functional>
#include <random>
//#include <boost/multiprecision/cpp_int.hpp>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)
#define llrep(i, n) for(ll i = 0; i < n; ++i)
#define llREP(i, m, n) for(ll i = m; i < n; ++i)
#define llrrep(i,n) for(ll i = n; i >= 0; --i)
#define llRREP(i, m, n) for(ll i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
using pil = std::pair<int, long long>;
using pli = std::pair<long long, int>;
using plpii = std::pair<long long, std::pair<int, int>>;
using pdd = std::pair<double, double>;
using pis = std::pair<int, std::string>;
using pci = std::pair<char, int>;

const long long INF = 1000000000000000001;
const long long _MOD_ = 1000000000000000009;
const long long _MOD = 1000000007;
const long long MOD = 998244353;
const int ALPHABET = 27;
const double pi = 3.14159265358979;

using namespace std;
//namespace mp = boost::multiprecision;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];

	int* num = new int[n];
	memset(num, 0, sizeof(int)*n);
	bool flag = false;
	rep(i, n) {
		++num[a[i] - 1];
		++num[b[i] - 1];

		if (num[a[i] - 1] > n || num[b[i] - 1] > n) {
			flag = true;
			break;
		}
	}
	delete[] num;

	if (flag) {
		cout << "No" << "\n";
		return 0;
	}

	int* c = new int[n + 1];
	int* d = new int[n + 1];
	memset(c, -1, sizeof(int)*(n + 1));
	memset(d, -1, sizeof(int)*(n + 1));
	rep(i, n) {
		c[a[i]] = i;
		d[b[i]] = i;
	}

	int x = 0;
	REP(i, 1, n + 1) {
		c[i] = max(c[i], c[i - 1]);
		d[i] = max(d[i], d[i - 1]);

		x = max(x, c[i] - d[i - 1]);
	}

	cout << "Yes" << "\n";
	rep(i, n) {
		cout << b[(i + n - x) % n] << " ";
	}

	cout << "\n";

	return 0;
}
