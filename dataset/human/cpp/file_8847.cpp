#include<iostream>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cmath>
#include<complex>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<string> A(N), B(M);
	REP(i, N) cin >> A[i];
	REP(i, M) cin >> B[i];
	for (int i = 0;i <= N - M;i++) {
		for (int j = 0;j <= N - M;j++) {
			bool flag = true;
			for (int k = 0;k < M;k++) {
				if (B[k] != A[i + k].substr(j, M)) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";

	return 0;
}
