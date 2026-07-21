#include<iostream>
#include<map>
#include<algorithm>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>

#define INF 1050000000
#define MOD 1000000007

using namespace std;

int main() {
	int n; cin >> n;
	long long int a[n];
	for (int i = 0; i < n; i++) {
		cin >>a[i];
	}
	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
	}

	long long int ans = pow(10, 18);

	for (int i = 0; i < n - 1; i++) {
		long long int tmp = abs(a[i] - (a[n - 1] - a[i]));
		ans = min(ans, tmp);
	}

	cout << ans << endl;

}
