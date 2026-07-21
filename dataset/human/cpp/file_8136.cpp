#include <iostream>
#include <climits>

long long int N;
long long int a[200001] = {};
long long int least = INT_MAX;
long long int b = 0;
long long int c = 0;

using namespace std;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		c += a[i];
	}
	for (int i = 1; i < N; i++) {
		b += a[i];
		c -= a[i];
		if (least > abs(b - c))least = abs(b - c);
	}
	cout << least << endl;
}
