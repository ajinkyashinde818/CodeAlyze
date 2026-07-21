#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int n,ans = 0;
	vector<int>a(3);
	cin >> a[0]>>a[1]>>a[2]>>n;
	sort(a.rbegin(), a.rend());
	for (int i = 0; i <= n / a[0]; i++) {
		int hoge = n - a[0] * i;
		if (hoge == 0) {
			ans++;
			continue;
		}
		for (int j = 0; j <= hoge/a[1]; j++) {
			int fuga = hoge - a[1] * j;
			if (hoge == 0) {
				ans++;
				continue;
			}
			if (fuga % a[2] == 0) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}
