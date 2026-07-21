#include<iostream>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<climits>
#include<map>
#include<string>
#include<functional>
#include<iomanip>

using namespace std;
typedef long long ll;

ll R, G, B, N;
ll ans = 0;

int main() {
	cin >> R >> G >> B >> N;
	for (int i = 0; i*R <= N; i++) {
		for (int j = 0; i*R + j*G <= N; j++) {
			if ((N - i*R - j*G) % B == 0)ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
