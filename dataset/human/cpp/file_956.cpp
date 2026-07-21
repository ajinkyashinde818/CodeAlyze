#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;

int main(void) {
	int R, G, B, N, answer = 0, num1, num2;
	cin >> R >> G >> B >> N;
	for (int i = 0; i <= N / R; i++) {
		num1 = N - R * i;
		for (int j = 0; j <= num1 / G; j++) {
			num2 = num1 - G * j;
			if (num2 % B == 0) {
				answer++;
			}
		}
	}
	cout << answer << endl;
	return 0;
}
