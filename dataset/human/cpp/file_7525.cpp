#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[229028], sum = 0, k = 0, ans = 1145141919810000;
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i]; sum += a[i];
	}
	for (int i = 0; i < n - 1; i++){
		k += a[i];
		ans = min(ans, abs(k - (sum - k)));
	}
	cout << ans << endl;
}
