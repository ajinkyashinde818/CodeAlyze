#include <bits/stdc++.h>

using namespace std;

static const int INF = 1e9 + 7;

template<typename T>
using Vec = vector<T>;

template<typename T, typename T2>
using P = pair<T, T2>;

template<typename... Args>
using Tup = tuple<Args...>;

template<typename T>
using qp = priority_queue<T, Vec<T>, greater<T> >;

template<typename T>
using pq = priority_queue<T>;

using llong = long long;
using ullong = unsigned long long;
using uint = unsigned int;

template<typename T>
T gcd(T x, T y)
{
	return y ? gcd(y, x % y) : x;
}

void hawawa()
{
	int n, m;
	cin >> n >> m;
	Vec<string> a(n), b(m);
	for (auto&& i : a) {
		cin >> i;
	}
	for (auto&& i : b) {
		cin >> i;
	}
	for (int i = 0; i + m <= n; i++) {
		for (int j = 0; j + m <= n; j++) {
			if (a[i].substr(j, m) == b[0]) {
				for (int k = 1; k < m; k++) {
					if (a[i + k].substr(j, m) != b[k]) {
						goto end;
					}
				}
				cout << "Yes\n";
				return;
			}
		end:;
		}
	}
	cout << "No\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	hawawa();
}
