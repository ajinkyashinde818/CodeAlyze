#include <bits/stdc++.h>
using namespace std;
template<typename T = int> vector<T> create(size_t n){ return vector<T>(n); }
template<typename T, typename... Args> auto create(size_t n, Args... args){ return vector<decltype(create<T>(args...))>(n, create<T>(args...)); }
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, r; cin >> n >> r;
	if(n >= 10) cout << r << '\n';
	else cout << r + 100 * (10 - n) << '\n';
	return 0;
}
