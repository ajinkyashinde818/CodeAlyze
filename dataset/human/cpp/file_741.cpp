#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int R, G, B, N, ans = 0;
	cin >> R >> G >> B >> N;
	for(int r = 0; r <= N; r += 1)
		for(int g = 0; g <= N; g += 1)
			if(r * R + g * G <= N and (N - r * R - g * G) % B == 0) ans += 1;
	cout << ans;
	return 0;
}
