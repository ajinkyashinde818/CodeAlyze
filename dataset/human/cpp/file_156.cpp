#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef vector<int> Vi;
typedef vector<lli> Vl;
typedef pair<int, int> Pii;
typedef pair<lli, lli> Pll;


//===


int main()
{
	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int cnt = 0;

	int mr = N / R;
	for (int r = 0; r <= mr; ++r) {
		int mg = (N - R * r) / G;
		for (int g = 0; g <= mg; ++g) {
			int b = (N - R * r - G * g) / B;
			if (R * r + G * g + B * b == N) {
				++cnt;
			}
		}
	}

	cout << cnt << endl;
}
