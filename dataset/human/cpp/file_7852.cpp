#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
#include<sstream>
using namespace std;

int main() {

	long long N;
	cin >> N;

	vector<long long> a(N, 0);
	vector<long long> v(N, 0);

	cin >> a[0];
	v[0] = a[0];
	for (long long i = 1; i < N; i++) {
		cin >> a[i];
		v[i] = v[i - 1] + a[i];
	}

	long long v_min = 0;
	long long val;
	bool jdg = false;
	for (long long i = 0; i < N - 1; i++) {
		val = abs(2 * v[i] - v.back());
		if (val < v_min || jdg == false) {
			v_min = val;
			jdg = true;
		}
	}

	cout << v_min << endl;

	return 0;
}
