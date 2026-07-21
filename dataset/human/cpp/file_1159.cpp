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
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int ans = 0;
	for (int i = 0; i <= 3000; i++) {
		if (i * R > N) break;
		for (int j = 0; j <= 3000; j++) {
			if (i * R + j * G > N) break;
			ans += !((N - (i * R) - (j * G)) % B);
		}
	}
	cout << ans << "\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	hawawa();
}
