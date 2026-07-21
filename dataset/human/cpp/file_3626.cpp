#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm> 
#include <math.h>
#include <queue>
#include <functional>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;

const ll INF = 1e15;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main(void) {
	int N,cnt = 0;
	ll mi = INF, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll s; cin >> s;
		if (s < 0)cnt++;
		sum += abs(s);
		mi = min(mi, abs(s));
	}

	if (cnt % 2 == 0)cout << sum << endl;
	else cout << sum - 2*mi << endl;

}
