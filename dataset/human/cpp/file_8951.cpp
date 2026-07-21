#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <numeric>

#include <map>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <bitset>
#include <math.h>

#define INF 100100100

typedef long long int llint;

using namespace std;

typedef pair<int, int>Pii;

#define pi 3.141592653589793

int main() {
	int n,m;
	cin >> n >> m;
	vector<string>a(n), b(m);
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++)cin >> b[i];
	for (int i = 0; i + m -1 < a[0].size(); i++) {
		for (int j = 0; j + m -1 < n; j++) {
			bool flag = true;
			for (int k = 0; k < b[0].size(); k++) {
				for (int l = 0; l < m; l++) {
					if (a[i + k][j + l] != b[k][l]) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
