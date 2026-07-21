#include <iostream>
#include <string>
#include<algorithm>
#include <vector>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
using namespace std;

typedef long long ll;
int modulo = 1000000007; // 10^9 + 7


int main() {
	int N; cin >> N;
	int a[N];
	for (int i = 0; i < N; i++) cin >> a[i];

	ll hand_A = 0; // Aのカード a[0]～a[i]
	ll hand_B = 0; // Bのカード a[i+1]～a[N-1]
	for (int j = 0; j < N; j++) hand_B += a[j]; // 最初に全部足しておく
												// 後で調整

	ll ans = 1000000000000000;
	for (int i = 0; i < N - 1; i++) {
		hand_A += a[i]; 
		hand_B -= a[i];
		ll temp = abs(hand_A - hand_B);
		ans = min(ans, temp);
	}
	cout << ans << endl;

	return 0;
}
