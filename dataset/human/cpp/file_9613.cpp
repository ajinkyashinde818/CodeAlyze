#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctype.h>
#include <map>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cctype>
#include <queue>
#include <set>
#include <list>
#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define DescSort(a) sort(a.begin(),a.end(),std::greater<int>())

using namespace std;
typedef long long ll;
const ll INF=1e9+7;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	rep(i, 0, n)cin >> a[i];
	rep(i, 0, m)cin >> b[i];
	bool exist = false;
	rep(i, 0, n) {
		rep(j, 0, n) {
			if (i + m - 1 >= n || j + m - 1 >= n)continue;
			bool match = true;
			rep(k, 0, m) {
				rep(l, 0, m) {
					if (a[i + k][j + l] != b[k][l]) {
						match = false;
						break;
					}
				}
			}
			if (match)exist = true;
		}
	}
	if (exist)cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
