#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<iomanip>
#include <functional>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int INF = 1 << 30;
const double EPS = 1e-10;
const double pi = 3.14159265359;
//cout << fixed << std::setprecision(9)
//memset(a, 0, sizeof(a));
//--------------------------

int n, m;
char a[111][111];
char b[111][111];

int main()
{
	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < m;j++) {
			cin >> b[i][j];
		}
	}

	int flag = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			flag = 1;
			for (int ii = 0;ii < m;ii++) {
				for (int jj = 0;jj < m;jj++) {
					if (a[i + ii][j + jj] != b[ii][jj]) flag = 0;
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
