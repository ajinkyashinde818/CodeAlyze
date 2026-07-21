#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <queue>
#include <random>
#include <cstdint>
#include <bitset>
#include <iomanip>
#include <utility>
#include<map>
#include<functional>
using namespace std;
using ll = long long;
const int mod = 1000000007;

//

int main() {
	int n,memo=1000000;
	ll ans[500][500];
	cin >> n;
	for (int i = 0; i <= sqrt(n*2); i++) {
		if (i*(i + 1) == n*2) {
			memo = i;
			break;
		}
	}
	if (memo == 1000000) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	int count = 1;
	for (int i = 0; i < memo; i++) {
		for (int j = i; j < memo; j++) {
			ans[i][j] = count;
			ans[j+1][i] = count;
			count++;
		}
	}
	cout << memo + 1 << endl;
	for (int i = 0; i < memo+1; i++) {
		cout << memo<<' ';
		for (int j = 0; j < memo; j++) {
			cout << ans[i][j];
			if (j != memo - 1)cout << ' ';
		}
		cout << endl;
	}

	return 0;
}
