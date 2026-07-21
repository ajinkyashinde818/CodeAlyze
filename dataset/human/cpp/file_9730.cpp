#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;

// マクロ&定数 ============================================================
typedef unsigned int uint;
typedef long long ll;
//typedef pair<int, int> P;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<double> vdouble;
typedef vector<bool> vbool;

typedef vector<vector<int>> vvint;
typedef vector<vector<ll>> vvll;
typedef vector<vector<double>> vvdouble;
typedef vector<vector<bool>> vvbool;

const int INF = 1e9 + 1;
const ll LLINF = 1e17 + 1;
const int DX[9] = { 0,0,1,-1, 1, 1, -1, -1, 0 }; // 4;４近傍
const int DY[9] = { 1,-1,0,0, 1, -1, 1, -1, 0 }; // 8:８近傍 9:(0,0)を含む
const ll MOD = 1e9 + 7; //10^9 + 7
const double PI = 3.14159265358979323846264338327950288;
//========================================================================


int main() {

	//==================================
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(30);
	//==================================


	int N;
	cin >> N;

	string S;
	cin >> S;

	sort(S.begin(), S.end());

	
	ll ans = 1;
	for (int i = 0; i < N; i++) {


		int seq = 0;

		for (int j = i; j < N; j++) {
			if (S[i] == S[j]) {
				seq++;

				if (j == N - 1) {
					ans *= (seq+1);
					ans %= MOD;
					cout << ans - 1;
					return 0;
				}
			}
			else {
				i = j-1;
				ans *= (seq+1);
				ans %= MOD;
				break;
			}
		}
			   		 
	}


	cout << ans - 1;


}
