#include <bits/stdc++.h>
 using namespace std;

bool is_minus(long i) {
	return (i < 0);
}

int main()
{
	//input
	int N; cin >> N;
	vector<long> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<long> B;

	//compute
	long long ans = 0;
	size_t n_count = count_if(A.begin(), A.end(), is_minus);

	if (n_count % 2 == 0) {
		for (int i = 0; i < N; i++) {
			ans = ans + abs(A[i]);
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			ans = ans + abs(A[i]);
			B.push_back(abs(A[i]));
		}
		long min = *min_element(B.begin(), B.end());
		ans = ans - 2 * min;
	}

	//output
	cout << ans << endl;
}
