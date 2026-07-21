#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <string>
using namespace std;

int main()
{
	int n;
	vector<int> ns(3);
	cin >> ns[0] >> ns[1] >> ns[2] >> n;
	sort(ns.begin(), ns.end());

	int cnt = 0, tmp1, tmp2;
	for (int i = 0; i <= n / ns[2]; ++i) {
		tmp1 = ns[2] * i;
		for (int j = 0; j <= (n - tmp1) / ns[1]; ++j) {
			tmp2 = tmp1 + ns[1] * j;
			if ((n - tmp2) % ns[0] == 0)++cnt;
		}
	}


	cout << cnt << endl;
	return 0;
}
