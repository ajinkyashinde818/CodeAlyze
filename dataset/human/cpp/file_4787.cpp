#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bitset>
using ll = long long;
using namespace std;
constexpr ll INF = 1LL << 60;

ll n, r;

int main() {
	cin >> n >> r;
	if (n >= 10) cout << r;
	else cout << r + 100 * (10 - n);
	return 0;
}
