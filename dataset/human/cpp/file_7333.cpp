#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include <iomanip>
#include<deque>
#include<stack>
#include<set>
#include <numeric>
#include<bitset>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
//typedef pair<int, int> P;
const int INF = 1e9 + 1;
const ll LLINF = 1e17 + 1;
const double EPS = 0.000000000001;
const int DX[9] = { 0,0,1,-1, 1, 1, -1, -1, 0 }; // 4;４近傍
const int DY[9] = { 1,-1,0,0, 1, -1, 1, -1, 0 }; // 8:８近傍 9:(0,0)を含む
const int MOD = 1e9 + 7; //10^9 + 7
const double PI = 3.14159265358979323846264338327950288;


int main() {

	//==================================
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	//==================================


	ll N, M;
	cin >> N;
	vector<ll> A(N);
	for (ll i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (ll i = 1; i < N; i++) {
		A[i] += A[i - 1];
	}

	ll ans = LLINF;
	for (ll i = 0; i < N- 1; i++) {
		ans = min(ans, abs( 2 * A[i] - A[N - 1]));
	}

	cout << ans;

}
