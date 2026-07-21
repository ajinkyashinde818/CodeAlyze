#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, i, j, k, a, b;
	bool valid = false;

	cin >> n >> m;
	vector<string> sa(n), sb(m);
	for (i = 0; i < n; i++) cin >> sa[i];
	for (i = 0; i < m; i++) cin >> sb[i];

	for (i = 0; i <= n - m; i++) {
		for (j = 0; j <= n - m; j++) {
			bool match = true;
			for (a = 0; a < m; a++) {
				for (b = 0; b < m; b++) {
					if (sa[i + a][j + b] != sb[a][b]) match = false;
				}
			}
			if (match) valid = true;
		}
	}
	if (valid) cout << "Yes";
	else cout << "No";

	return 0;
}
