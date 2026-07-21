#include "bits/stdc++.h"
using namespace std;

/*第二引数で第一引数を割ったときの切り上げの計算*/
long long int maxtime(long long int x, long long int y) {
	return(x + y - 1) / y;

}
/*最大公約数*/
long long int lcm(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;

	if (number2 > number1) {
		m = number2;
		n = number1;
	}
	long long int s = -1;
	while (s != 0) {
		s = m % n;
		m = n;
		n = s;
	}
	return m;
}
/*最大公倍数*/
long long int gcd(long long int number1, long long int number2) {
	long long int m = number1;
	long long int n = number2;
	return m / lcm(m, n) * n;
}
int main() {
	int N;
	cin >> N;
	long long int sum = 0;
	vector<int> c;
	long long int pulus = 0;
	long long int check = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		c.push_back(abs(a));
		sum = sum + abs(a);
		if (a == 0) {
			check = 1;
		}
		if (a < 0) {
			pulus++;
		}
	}
	sort(c.begin(), c.end());
	if (check == 1) {
		cout << sum;
	}
	else {
		if (pulus % 2 == 0) {
			cout << sum;
		}
		else {
			int d = c[0] * 2;
			cout << sum - d;
		}
	}
}
