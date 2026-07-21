#include <iostream>
using namespace std;

int main()
{
	long long n;
	cin >> n;

	long long count = 0;
	long long ret = 0;
	long long min = 10000000000;
	for (long long i = 0; i < n; ++i) {
		long long a;
		cin >> a;
		if (a < 0) {
			++count;
			if (-a < min) {
				min = -a;
			}
			ret += -a;
		}
		else {
			if (a < min) {
				min = a;
			}
			ret += a;
		}
	}

	if (count % 2 == 1) {
		ret -= min * 2;
	}

	cout << ret << endl;


	return 0;
}
