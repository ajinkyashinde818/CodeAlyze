#include <bits/stdc++.h>
typedef long long i64;
using std::cout;
using std::endl;
using std::cin;

int main() {
	int n; cin >> n;
	int tmp = -1;
	for(int i = 0; i * (i + 1) <= 2 * n; i++) {
		if(i * (i + 1) == 2 * n) {
			tmp = i;
		}
	}
	if(tmp == -1) {
		cout << "No" << endl;
		return 0;
	}
	
	int tail = 1;
	std::vector<std::vector<int>> vec(tmp + 1, std::vector<int>(tmp, 0));
	for(int i = 0; i < tmp + 1; i++) {
		for(int j = 0; j < i; j++) vec[i][j] = vec[j][i - 1];
		for(int j = i; j < tmp; j++) vec[i][j] = tail++;
	}
	
	cout << "Yes" << endl;
	cout << tmp + 1 << endl;
	for(int i = 0; i < tmp + 1; i++) {
		cout << vec[i].size() << " ";
		for(auto v : vec[i]) cout << v << " ";
		cout << endl;
	}
	return 0;
}
