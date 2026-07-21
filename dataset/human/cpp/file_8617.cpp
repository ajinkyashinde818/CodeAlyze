#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	char A[50][50], B[50][50];

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> A[y][x];
		}
	}
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < m; x++) {
			cin >> B[y][x];
		}
	}

	bool exists = false;
	for (int ay = 0; ay < n - m + 1; ay++) {
		for (int ax = 0; ax < n - m + 1; ax++) {
			
			bool judge = true;
			for (int by = 0; by < m; by++) {
				for (int bx = 0; bx < m; bx++) {
					if (A[ay + by][ax + bx] != B[by][bx]) judge = false;
				}
			}

			if (judge) exists = true;
		}
	}

	if (exists) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
