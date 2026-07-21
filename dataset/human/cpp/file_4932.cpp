#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int n, r;
	cin >> n >> r;
	if (n >= 10) {
		cout << r;
	}
	else {
		cout << 100 * (10 - n) + r;
	}
}
