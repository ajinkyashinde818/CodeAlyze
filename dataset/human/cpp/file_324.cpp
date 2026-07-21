#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
using namespace std;

int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int ans = 0;
	for (int i = 0; i <= 3000; i++) {								//iはRの数
		for (int j = 0; j <= 3000; j++) {
			int k = R * i + G * j;
				if (N >= k && (N - k) % B == 0) {
					ans++;
				}
										
			}
	}
	cout << ans  << endl;
}
