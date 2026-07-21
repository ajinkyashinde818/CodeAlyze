#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	int N;
	cin >> N;
	int mn = INF;
	int sum = 0;
	int minus = 0;
	rep(i, N) {
		int A;
		cin >> A;
		if (A <= 0) {
			minus++;
			A *= -1;
		}
		mn = min(mn, A);
		sum += A;
	}
	if (minus % 2 == 0)cout << sum;
	else {
		sum -= 2 * mn;
		cout << sum;
	}
}
