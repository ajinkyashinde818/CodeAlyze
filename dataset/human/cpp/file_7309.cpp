#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long int a[200005], S[200005];

int main(void) {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= N; i++) {
		S[i] = S[i - 1] + a[i];
	}
	long long int ans = 1000000000000000;
	long long int tmp;
	for (int i = 1; i <= N - 1; i++) {
		tmp = abs(S[i] - (S[N] - S[i]));
		ans = min(ans, tmp);
	}

	cout << ans << endl;
	//system("pause");
	return 0;
}
