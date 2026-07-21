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
#include "cassert"

using namespace std;

//const long long int MOD = 1000000007;
const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	long long int sum = 0;
	int m = 0;
	long long int le = MOD;
	int zero = 0;
	for (int i = 0; i < N; i++) {
		cin >> M;
		sum += abs(M);
		le = min(le, abs(M));
		m += M < 0;
		zero += !M;
	}
	if ((m & 1)&&(!zero))sum -= le*2;
	cout << sum << endl;
	return 0;
}
