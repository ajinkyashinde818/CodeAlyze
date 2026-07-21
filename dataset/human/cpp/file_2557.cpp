#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include<vector>
#include<utility>
#include<fstream>
#include<queue>
#include <iomanip>
using namespace std;
typedef long long ll;
#define rep(i,k) for(i=0;i<k;i++)
#define P pair<ll,ll>
int t[2005], u[200];
ll mod = 1000000007;

ll i, a, b, c, k, n, m, z = 0;
char s[100005];
int main() {
	cin >> n ;
	b = 0;
	c = 10000000000;
	rep(i, n) {
		cin >> a;
		if (a < 0) {
			b++; a = -a;
		}
		c = min(a, c);
		z += a;
	}
	if (b % 2 == 1)cout <<( z - 2*c);
	else cout << z;
}
