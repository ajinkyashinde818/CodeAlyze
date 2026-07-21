#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <stack> // s.top()
#include <bitset>
#include <queue> // s.front()
using namespace std;

typedef long long Int;
typedef pair<Int,Int> P;
#define print(x) cout<<(x)<<endl

#define INF10 10000000000
#define INF5 100000
#define EPS 1e-10
#define MOD 1000000007


int main() {
	int n, m;
	string a[100], b[100];
	cin >> n >> m;
	bool score = false;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			bool tmpscore = true;
			for (int x = 0; x < m; x++) {
				for (int y = 0; y < m; y++) {
					if (a[i + x][j + y] == b[x][y]) {
						continue;
					}
					else tmpscore = false;
				}
			}
			if (tmpscore == true)score = true;
		}
	}
	if (score)print("Yes");
	else print("No");





	return 0;
}
