#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdio.h>

using namespace std;

//typedefリスト
typedef vector<long long int> vint;
typedef vector<vector<long long int>> vvint;
typedef vector<string> vstr;
typedef long long int llint;

llint gcd(llint x, llint y) {
	while (y != 0) {
		if (x > y) {
			llint r = x % y;
			x = y;
			y = r;
		}
		else {
			llint r = y % x;
			y = r;
		}
	}
	return x;
}

int main(void) {
	int n;
	cin >> n;
	cout << n * 32 << endl;
}
