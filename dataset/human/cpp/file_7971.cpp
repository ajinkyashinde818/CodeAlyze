#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<long long> v;
	int num;
	long long total = 0;
	for (int i = 0; i < N; i++) {
		cin >> num;
		total += num;
		v.push_back(num);
	}

	long long  m = LLONG_MAX;
	long long  x = 0;
	for (int i = 0; i < N - 1; i++) {
		x += v[i];

		if ( x > total - x)
			m = min(m, x - (total - x));
		else
			m = min(m, (total - x) - x);
//		cout << x << ' ' << m << endl;
	}

	cout << m << endl;

	return 0;

}
