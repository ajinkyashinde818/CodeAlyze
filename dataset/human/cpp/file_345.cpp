#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(a) a.begin(),a.end()

int main() {
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int ans = 0;
	for (int r = 0; r <= (N / R); r++) {
		for (int g = 0; g <= (N / G); g++) {
			int rest = N - r * R - g * G;
			if (rest % B == 0 && rest >= 0) {
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
