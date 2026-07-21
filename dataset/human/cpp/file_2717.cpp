#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

int main() {
	int n;
	cin >> n;
	int a;
	ll sum = 0;
	int count = 0;
	int mina = 1000000009;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < 0) {
			a *= -1;
			count++;
		}
		sum += a;
		mina = min(a, mina);
	}
	if (count % 2 == 1) {
		cout << sum - mina * 2 << endl;
	}
	else {
		cout << sum << endl;
	}
	return 0;
}
