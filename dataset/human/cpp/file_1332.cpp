#include "bits/stdc++.h"

typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
int main() {
	int R, G, B, N, sum, res = 0;
	cin >> R >> G >> B >> N;

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			sum = N - (i*R) - (j*G);
			if (sum >= 0 && sum%B == 0) {
				res++;
			}
		}
	}
	cout << res << endl;
}
