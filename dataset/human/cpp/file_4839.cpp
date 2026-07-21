#include<iostream>
#include<cstdlib>
#include<utility>
#include<tuple>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std;
using ll = long long;

int main() {

	int n, r;

	cin >> n >> r;

	int ans = 0;
	if (n <= 10) ans = 100 * (10 - n) + r;
	else ans = r;

	cout << ans << endl;

	return 0;
}
