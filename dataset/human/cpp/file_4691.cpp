#include <algorithm>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;
	if (n < 10)
		cout << k + (10 - n) * 100 << endl;
	else
		cout << k << endl;

	return 0;
}
