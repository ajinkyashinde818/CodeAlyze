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
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int INF = 1e15;
const int MOD = 1e9 + 7;
const double PI = 3.14159265358979323846;

signed main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int cnt = 0;
	for (int i = 0; i <= N / R; i++) {
		for (int j = 0; j <= (N - i * R) / G; j++) {
			if ((N - i * R - j * G) % B == 0)cnt++;
		}
	}
	cout << cnt;
}
