#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <set>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<string> fieldA(n);
	for (int i = 0; i < n; ++i) {
		cin >> fieldA[i];
	}

	vector<string> fieldB(m);
	for (int i = 0; i < m; ++i) {
		cin >> fieldB[i];
	}

	for (int i = 0; i < n - m + 1; ++i) {
		for (int j = 0; j < n - m + 1; ++j) {
			bool flag = true;
			for (int c = 0; c < m; ++c) {
				if (!flag) break;
				for (int k = 0; k < m; ++k) {
					if (fieldA[i + c][j + k] != fieldB[c][k]) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;

	return 0;
}
