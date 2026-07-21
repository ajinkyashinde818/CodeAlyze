#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long a[200020];
int main() {
	int n;
#define int long long
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int mi = 100000000000000007;
	int sum1 = 0;
	for (int i = 0; i < n - 1; i++) {
		sum1 += a[i];
		if (abs((sum - sum1) - sum1) < mi) {
			mi = abs((sum - sum1) - sum1);
		}
	}
	cout << mi << endl;
	return 0;
}
