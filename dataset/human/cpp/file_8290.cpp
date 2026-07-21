#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>
#include <numeric>
#include <limits>
#include <queue>
#include <cstdint>
#include<iomanip>
#define ll long long int
#define rep(i,rept) for (int (i) = 0; (i) < rept; (i)++)
#define rept(i,n,rept) for (int (i) = n; (i) < rept; (i)++)
#define Yes(b) std::cout<< (b ? "Yes" : "No")<<std::endl
#define YES(b) std::cout<< (b ? "YES" : "NO")<<std::endl
#define fr first
#define se second
#define lolo 92233720368547757
#define susu 1000000007
typedef std::pair<int, int> pp;
typedef std::pair<ll, ll> llpp;
using namespace std;
int main() {
	bool b = false;
	int n, m;
	string s[50],str[50];
	cin >> n >> m;
	rep(i, n) {
			cin >> s[i];
	}
	rep(i, m) {
		cin >> str[i];
	}
	rep(i, n - m + 1) {
		rep(j, n - m + 1) {
			b = true;
			rep(k, m) {
				rep(l, m) {
					if (s[i + k][j + l] != str[k][l]) {
						b = false;
						break;
					}
					if (k == m - 1 && l == m - 1) {
						Yes(true);
						return 0;
					}
				}
				if (!b) {
					break;
				}
			}
		}
	}
	Yes(false);
	return 0;
}
