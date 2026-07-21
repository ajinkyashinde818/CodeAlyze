#include <iostream>

using namespace std;

int main(void)
{
	unsigned long long answer = 0;
	unsigned int n;
	int a[100000];
	unsigned int min;
	unsigned int minIdx;

	cin >> n;

	cin >> a[0];
	min = abs(a[0]);
	minIdx = 0;

	for (int i = 1; i < n; i++) {
		cin >> a[i];
		if (abs(a[i]) < min) {
			min = abs(a[i]);
			minIdx = i;
		}
	}
  
	for (int i = 0; i < minIdx; i++) {
		if (a[i] < 0) {
			a[i] *= -1;
			a[i+1] *= -1;
		}
	}
  
	for (int i = n-1; i > minIdx; i--) {
		if (a[i] < 0) {
			a[i] *= -1;
			a[i-1] *= -1;
		}
	}

	for (int i = 0; i < n; i++) {
		answer += a[i];
	}

	cout << answer;
}
