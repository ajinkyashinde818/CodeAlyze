#include <iostream>

using namespace std;

int N;


int main()
{
	long long ans = 0;

	cin >> N;

	int min_abs = 1000000001;
	bool minus_odd = false;
	int tmp;

	for (int i = 0;i<N; i++) {
		cin >> tmp;
		if (tmp < 0) {
			minus_odd = !minus_odd;
			tmp *= -1;
		}
		min_abs = min(min_abs,tmp);
		ans += tmp;
	}

	if (minus_odd) {
		ans -= min_abs * 2;
	}


	cout << ans << endl;

	return 0;
}
