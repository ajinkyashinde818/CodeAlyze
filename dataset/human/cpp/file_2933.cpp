#include "bits/stdc++.h"
using namespace std;
int main() {
	int N, cunt = 0;
	long long res = 0, mini = 9999999999;
	cin >> N;
	vector<long long> A(N);
	for (int i = 0; i < N; i++){
		cin >> A.at(i);
		if (A.at(i)<0) {cunt++;	}
	}
	for (int i = 0; i < N; i++)
	{
		mini = min(mini, abs(A.at(i)));
		res += abs(A.at(i));
	}
	if (cunt % 2 == 0) {cout << res << endl;}
	else {
		res = res - 2 * mini;
		cout << res << endl;
	}
}
