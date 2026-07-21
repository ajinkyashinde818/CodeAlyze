#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	M = 1;
	while (M*(M - 1) / 2 < N)M++;
	if (M*(M - 1) / 2 != N) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	L = 0;
	R = 1;
	vector<vector<int>>v(M);
	for (int i = 1; i <= N; i++) {
		v[L].push_back(i);
		v[R].push_back(i);
		R++;
		if (R == M) {
			L++;
			R = L + 1;
		}
	}
	cout << M << endl;
	for (auto i : v) {
		cout << i.size();
		for (auto j : i)cout << " " << j;
		cout << endl;
	}
	return 0;

}
