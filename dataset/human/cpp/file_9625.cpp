#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<deque>
#include<numeric>
#include<algorithm>
#include<unordered_map>
#include<cmath>

using namespace std;
using ll = long long int;
constexpr int INF = 1 << 29;
constexpr ll MOD = ll(1e9 + 7);

int n, m;
vector<string> a, b;

bool is_sub_img(int x, int y) {
	bool ret = true;
	for (int i = 0; i < m; i++) {
		if (a[y + i].substr(x, m) != b[i]) {
			ret = false;
			break;
		}
	}
	return ret;
}


int main(void) {
	cin >> n >> m;
	a = vector<string>(n);
	b = vector<string>(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	string ret = "No";
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			if (is_sub_img(i, j)) {
				ret = "Yes";
				break;
			}
		}
	}
	cout << ret << endl;
	return 0;
}
