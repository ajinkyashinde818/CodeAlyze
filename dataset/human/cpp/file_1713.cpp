#include <bits/stdc++.h>
using namespace std;

void solve(long long N){
	map<int,int> mp;
	for(int i = 2; i * (i - 1) / 2 <= N; ++i) {
		if(i * (i - 1) / 2 == N) {
			vector<vector<int>> a(i);
			int cnt = 1;
			for(int j = 0; j < i; ++j) {
				for(int k = j + 1; k < i; ++k) {
					a[j].push_back(cnt);
					a[k].push_back(cnt);
					++cnt;
				}
			}
			cout << "Yes" << endl;
			cout << i << endl;
			for(int j = 0; j < i; ++j) {
				cout << a[j].size();
				for(auto k: a[j]) {
					cout << " " << k;
				}
				cout << endl;
			}
			return;
		}
	}
	cout << "No" << endl;
}

int main(){	
	long long N;
	scanf("%lld",&N);
	solve(N);
	return 0;
}
