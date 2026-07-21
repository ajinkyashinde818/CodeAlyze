//#include "pch.h"
#include <iostream>
#include <math.h>

using namespace std;


int main() {

	int n;
	long long a[100001];


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	bool minusCount = true; //trueは偶数個　false奇数個
	long long wkmin = abs(a[0]);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			a[i] *= -1;
			minusCount = !minusCount;
		}

		if (a[i] < wkmin)wkmin = a[i];
		sum += a[i];
	}

	if (!minusCount) {
		sum -= (wkmin * 2);
	}

	cout << sum << endl;

//	system("pause");


}
