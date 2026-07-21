#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long long> Subsum(N,0);
	cin >> Subsum[0];
	for (int i = 1; i < N; i++) {
		int a;
		cin >> a;
		Subsum[i] = Subsum[i - 1] + a;
	}
	long long MIN = 2 * pow(10, 14);
	for (int i = 0; i < N - 1; i++) MIN = min(MIN, abs(Subsum[N - 1] - 2 * Subsum[i]));
	cout << MIN << endl;
}
