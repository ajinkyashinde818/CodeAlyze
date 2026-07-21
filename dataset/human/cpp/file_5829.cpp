#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

ll solve(ll c, const vector<ll>& x, const vector<ll>& v){
	const int n = x.size();
	vector<ll> v_acc(n + 1);
	for(int i = 0; i < n; ++i){ v_acc[i + 1] = v_acc[i] + v[i]; }
	multiset<ll> s;
	ll answer = 0;
	for(int i = 0; i < n; ++i){
		const ll score = v_acc[i + 1] - x[i];
		answer = max(answer, score);
		s.insert(score);
	}
	for(int i = n - 1; i > 0; --i){
		s.erase(s.find(v_acc[i + 1] - x[i]));
		answer = max(answer, (v_acc[n] - v_acc[i]) - 2 * (c - x[i]) + *s.rbegin());
	}
	return answer;
}

int main(){
	ios_base::sync_with_stdio(false);
	ll n, c;
	cin >> n >> c;
	vector<ll> x(n), v(n);
	for(int i = 0; i < n; ++i){ cin >> x[i] >> v[i]; }
	ll answer = solve(c, x, v);
	reverse(x.begin(), x.end());
	reverse(v.begin(), v.end());
	for(int i = 0; i < n; ++i){ x[i] = c - x[i]; }
	answer = max(answer, solve(c, x, v));
	cout << answer << endl;
	return 0;
}
