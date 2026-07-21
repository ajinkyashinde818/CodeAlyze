#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {

	int r, g, b, N;
	cin >> r >> g >> b >> N;
	int a = 0;

	for (int i = 0; i <= N; i += r) {
		int N2 = N - i;
		for (int j = 0; j <= N2; j += g) {
			if ((N2 - j) % b == 0) a++;
		}
	}

	cout << a << endl;

	return 0;
}
