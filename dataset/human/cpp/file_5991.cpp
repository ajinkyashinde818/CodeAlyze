#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
static const int MAX_N = 100000;

int N;
ll C;
ll x[MAX_N], v[MAX_N];
ll memo1[MAX_N + 1], memo2[MAX_N + 1], memo3[MAX_N + 1], memo4[MAX_N + 1];

int main(){
	cin >> N >> C;
	for(int i = 0; i < N; i++) cin >> x[i] >> v[i];
	
	fill(memo1, memo1 + N + 1, 0LL);
	fill(memo2, memo2 + N + 1, 0LL);
	fill(memo3, memo3 + N + 1, 0LL);
	fill(memo4, memo4 + N + 1, 0LL);
	
	for(int i = 0; i < N; i++) memo1[i + 1] = memo1[i] + v[i];
	for(int i = 0; i < N; i++) memo2[i + 1] = memo2[i] + v[N - i - 1];
	for(int i = 0; i < N; i++) memo3[i + 1] = memo3[i] + v[i];
	for(int i = 0; i < N; i++) memo4[i + 1] = memo4[i] + v[N - i - 1];

	for(int i = 0; i < N; i++) memo1[i + 1] -= x[i];
	for(int i = 0; i < N; i++) memo2[i + 1] -= C - x[N - i - 1];
	for(int i = 0; i < N; i++) memo3[i + 1] -= 2 * x[i];
	for(int i = 0; i < N; i++) memo4[i + 1] -= 2 * (C - x[N - i - 1]);
	
	for(int i = 0; i < N; i++) memo1[i + 1] = max(memo1[i], memo1[i + 1]);
	for(int i = 0; i < N; i++) memo2[i + 1] = max(memo2[i], memo2[i + 1]);
	for(int i = 0; i < N; i++) memo3[i + 1] = max(memo3[i], memo3[i + 1]);
	for(int i = 0; i < N; i++) memo4[i + 1] = max(memo4[i], memo4[i + 1]);

	ll ans1 = 0LL, ans2 = 0LL;
	for(int i = 0; i < N + 1; i++){
		ans1 = max(ans1, memo1[i] + memo4[N - i]);
		ans2 = max(ans2, memo2[i] + memo3[N - i]);
	}
	cout << max(ans1, ans2) << endl;
	return 0;
}
