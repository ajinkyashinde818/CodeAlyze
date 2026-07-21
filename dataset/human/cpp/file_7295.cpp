#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

int main(){
	int N;
	int a[(int)2e5];

	long long maxl = 0;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		maxl += a[i];
	}
	long long add = a[0];
	maxl -= a[0];
	long long minl = abs(maxl - add);
	for (int i = 1; i < N-1; ++i) {
		maxl -= a[i];
		add += a[i];
		minl = min(minl, abs(maxl-add));
	}
	cout << minl << endl;

	return 0;
}
