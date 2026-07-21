#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> vec.at(i);
	}
	int A = 0;
	for (int i = 0; i < N; i++) {
		if (vec.at(i) == 0) {
			A++;
			break;
		}
	}
	int B = 0;
	for (int i = 0; i < N; i++) {
		if (vec.at(i) < 0) {
			B++;
		}
	}
	if (A == 0 && B % 2 == 1) {
		int mini = 1000000000;
		for (int i = 0; i < N; i++) {
			if (vec.at(i) < 0) {
				vec.at(i) = -vec.at(i);
			}
			mini = min(mini, vec.at(i));
		}
		long sum = 0;
		for (int i = 0; i < N; i++) {
			sum += vec.at(i);
        }
      cout << sum - 2 * mini << endl;
	}
	else {
		long sum = 0;
		for (int i = 0; i < N; i++) {
			if (vec.at(i) >= 0) {
				sum += vec.at(i);
			}
			else {
				sum -= vec.at(i);
			}
		}
		cout << sum << endl;
	}
}
