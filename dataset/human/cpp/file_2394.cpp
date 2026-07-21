#include "bits/stdc++.h"
using namespace std;

void yakusuu(int num, vector<int> &kouho)
{
	for (int i = 1; i * i <= num; i++) {
		if (num % i == 0) {
			kouho.push_back(i);
			kouho.push_back(num / i);
		}
	}
}

int main()
{
	int64_t n;
	cin >> n;
	int64_t sum = 0;
	int64_t abs_min = 1000000001;
	int cnt_minus = 0;
	for (int i = 0; i < n; i++) {
		int64_t a_in;
		cin >> a_in;
		
		sum += abs(a_in);
		abs_min = min(abs_min, abs(a_in));
		if (a_in < 0) {
			cnt_minus++;
		}
	}

	int64_t ans;
	if (cnt_minus % 2 == 0) {
		ans = sum;
	} else {
		ans = sum - abs_min * 2;
	}

	cout << ans << endl;
}
