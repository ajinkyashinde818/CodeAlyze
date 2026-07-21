#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	int N; cin >> N;
	long* A = new long[N];
	long sum = 0;

	bool oddflag = false;
	long m = 1000000005;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] > 0) {
			sum += A[i];
		}
		else {
			oddflag = !oddflag;
			sum -= A[i];
		}
		m = min(m, abs(A[i]));
	}
	
	if (oddflag) {
		sum -= m * 2;
	}

	cout << sum << endl;
	return 0;
}
