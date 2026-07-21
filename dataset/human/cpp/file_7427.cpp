#include<iostream>
#include<algorithm>
using namespace std;

long long a[200010];

int main() {
	int n;
	cin >> n;
	long long all = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		all += a[i];
	}
	long long sunuke = 0;
	long long ans = 10000000000 * 200010;;
	for (int i = 0; i < n - 1; i++) {
		sunuke += a[i];
		ans = min(ans, abs((all - sunuke) - sunuke));
	}
	cout << ans << endl;
	return 0;
}
