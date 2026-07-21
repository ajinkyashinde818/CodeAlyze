#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define ALL(x) (x).begin(),(x).end()
#define INF 999999999

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

int n, m;
VS a(51), b(51);

bool cheak(int x, int y) {
	bool flag = true;
	REP(i, m) {
		REP(j, m) {
			if (b[i][j] != a[i + x][j + y])flag = false;
		}
	}
	return flag;
}
int main() {
	bool flag = false;
	cin >> n >> m;
	REP(i, n)cin >> a[i];
	REP(i, m)cin >> b[i];

	REP(i, n - m + 1) {
		REP(j, n - m + 1) {
			if (cheak(i, j))flag = true;
		}
	}
	if (flag)puts("Yes");
	else puts("No");
}
