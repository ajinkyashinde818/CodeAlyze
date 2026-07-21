#include<iostream>
#include<cmath>

using namespace std;

bool issolve(int n) {
	//M^2-M-2*N=0
	double M = (1 + sqrt(1.0 + 8.0 * n)) / 2.0;
	int intM = M;
	if (M == (double)intM)return true;
	return false;
}

int ans[450 + 100][450 + 100];

int main() {
	int N;
	cin >> N;
	if (!issolve(N)) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	
	int M = (1 + sqrt(1.0 + 8.0 * N)) / 2.0;
	cout << M << endl;
	int cnt = 1;
	for (int i = 0; i < M; i++) {
		int size = 2 * N / M;
		cout << size << " ";
		for (int s = 0; s < size; s++) {
			if (size - i > s) {
				cout << cnt << " ";
				ans[i][s] = cnt;
				cnt++;
			}
			else {

				cout << ans[s - (size - i)][size - 1 - s] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
