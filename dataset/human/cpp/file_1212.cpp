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

	long long R, G, B, N;
	cin >> R >> G >> B >> N;

	long long ans = 0;
	long long val;
	for (long long r = 0; r <= N / R; r++) {
		for (long long g = 0; g <= ((N - r * R) / G); g++) {
			val = N - R*r - G*g;
			if (val % B == 0) {
				ans += 1;
			}
		}
	}

	cout << ans << endl;

	return 0;
}
