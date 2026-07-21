#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<numeric>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i = m; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a)  (a).rbegin(),(a).rend()
#define PI 3.14159265359
#define MOD 1000000007
typedef long long LL;

template<class T> inline void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> inline void chmin(T& a, T b) { if (a > b) { a = b; } }
template<class T> void print_vector(vector<T> vec) {
	cout << "[ ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "]" << endl;
}
template<class T> void print_pair_vector(vector<pair<T, T> > vec) {
	cout << "[ ";
	for (int i = 0; i < vec.size(); i++) {
		cout << "(" << vec[i].first << "," << vec[i].second << ") ";
	}
	cout << "]" << endl;
}

const int INF = 1 << 30;

int main(void) {
	int N, M;
	cin >> N >> M;

	vector<string> A(N);
	rep(i, N) cin >> A[i];

	vector<string> B(M);
	rep(i, M) cin >> B[i];

	bool template_is_included = false;
	for (int h = 0; h < N - M + 1; h++) {
		for (int w = 0; w < N - M + 1; w++) {
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < M; k++) {
					if (A[h + j][w + k] != B[j][k]) {
						goto NEXT_PATTERN_MATCH;
					}

					if (k == M - 1 and j == M - 1) {
						template_is_included = true;
					}
				}
			}
		NEXT_PATTERN_MATCH:
			continue;
		}
	}

	if (template_is_included) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
