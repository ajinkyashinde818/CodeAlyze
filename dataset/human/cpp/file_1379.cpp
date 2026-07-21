#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	int ans = 0;
	int R, G, B, N;
	int a, b, c;
	vector<int> vec(3);

	for (int i = 0; i < 3; i++) {
		cin >> vec.at(i);
	}
	cin >> N;

	sort(vec.begin(), vec.end());

	a= N/vec.at(2);

	for (int i = 0; i <= a; i++) {
		if (i * vec.at(2)==N) {
			ans++;
			continue;
		}
		b = (N - i * vec.at(2))/vec.at(1);
		for (int j = 0; j <= b; j++) {
			if (j * vec.at(1)==N- i * vec.at(2)) {
				ans++;
				continue;
			}
			if ((N - (i * vec.at(2) + j * vec.at(1))) % vec.at(0) == 0) {
				ans++;
 		    }
		}
	}



	cout << ans << endl;
}
