#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, tmp = 0;
	cin >> N;
	vector<long> A(N);
	long sum = 0;
	for (long& i : A) {
		cin >> i;
		if (i < 0) ++tmp;
		sum += labs(i);
	}
	if (tmp % 2) {
		sort(A.begin(), A.end(), [](long& a, long& b)->bool { return labs(a) < labs(b); });
		cout << sum - 2 * labs(A[0]);
	}
	else cout << sum;
}
