#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	int non = 0;
	long long mnum;
	long long res = 0;
	for (int i = 0; i < N; ++i) {
		long long num;
		cin >> num;
		if (num < 0) {
			++non;
			num = -num;
		}
		if (i == 0) {
			mnum = num;
		}
		else {
			mnum = min(num,mnum);
		}
		res += abs(num);
	}
	if (non%2 == 1) {
		res -= 2*mnum;
	}
	cout << res << endl;
	return 0;
}
