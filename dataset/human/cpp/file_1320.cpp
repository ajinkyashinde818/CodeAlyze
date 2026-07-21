#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	ll ans = 0;
	for (int r = 0; r <= N; r++) {
		for (int g = 0; g <= N; g++) {
			if (N - r * R - g * G >= 0 && (N - r * R - g * G) % B == 0) ans++;
		}
	}
	cout << ans << endl;
}
