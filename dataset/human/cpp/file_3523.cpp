#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	long int N;
	cin >> N;
	vector<long int>A(N);

	int mcount = 0;
	long long  int ans = 0;
	vector<long int>B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < 0) {
			mcount++;
			A[i] *= -1;
			B[i] = A[i];
		}
		else {
			B[i] = A[i];
		}
		ans += B[i];
	}
	//cout << ans << endl;
	sort(B.begin(), B.end());
	mcount %= 2;
	for (int j = 0; j < mcount; j++) {
		ans -= B[j]*2;
	}

	cout << ans << endl;


}
