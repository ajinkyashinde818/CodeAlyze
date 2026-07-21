#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int m;
	cin >> m;
	int n = 1;
	for(; n * (n - 1) / 2 < m; ++n);
	if(n * (n - 1) / 2 != m){
		cout << "No" << endl;
		return 0;
	}
	vector<vector<int>> solution(n);
	for(int i = 0, k = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j, ++k){
			solution[i].push_back(k);
			solution[j].push_back(k);
		}
	}
	cout << "Yes" << endl;
	cout << n << endl;
	for(const auto& v : solution){
		cout << v.size();
		for(const auto& x : v){ cout << " " << x + 1; }
		cout << endl;
	}
	return 0;
}
