#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, j = 0;
	long long a, s = 0, m = 1000000000;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;

		if (a < 0) {
			j++;
			a *= -1;
		}

		s += a;
		m = min(m, a);
	}

	if (j % 2 == 0)
		cout << s << endl;
	else
		cout << s - m * 2 << endl;

	return 0;
}
