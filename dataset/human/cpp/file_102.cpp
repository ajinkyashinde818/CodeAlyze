#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<string>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>
#include<queue>
#include<functional>
#include<iso646.h>
#include<bitset>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

int main(){
	ll R, G, B, N;
	cin >> R >> G >> B >> N;
	ll b1 = max(R, max(G, B));
	ll b3 = min(R, min(G, B));
	ll b2 = R + G + B - b1 - b3;

	ll i, j;
	ll ans = 0;
	for (i = 0; i*b1 <= N; i++){
		for (j = 0; i*b1 + j*b2 <= N; j++){
			if ((N - i*b1 - j*b2) % b3 == 0){
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
