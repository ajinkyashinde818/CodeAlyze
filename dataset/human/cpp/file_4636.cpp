#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main() {
	int n, r;
	cin >> n >> r;
	if (10 <= n) {
		cout << r << endl;
	}
	else {
		cout << r + 100 * (10 - n) << endl;
	}
	return 0;
}
