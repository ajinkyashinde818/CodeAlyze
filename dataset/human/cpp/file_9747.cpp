#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;


int main() {
	long num[26];
	int N;
	cin >> N;
	for (int i = 0; i < 26; i++) {
		num[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		c -= 'a';
		num[c]++;
	}

	long n = 1;
	for (int i = 0; i < 26; i++) {
		if (num[i] == 0) { continue; }
		n *= num[i] + 1;
		n %= 1000000007;
	}
	cout << n - 1;
	return 0;
}
