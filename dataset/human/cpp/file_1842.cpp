#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool used[200001];

int main()
{
	int n, m; cin >> n >> m;
	vector<int>e;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		e.push_back(a);
	}
	for (int i = e.size() - 1; i >= 0; i--) {
		if (used[e[i]] == false) {
			cout << e[i] << endl;
			used[e[i]] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (used[i] == false) cout << i << endl;
	}

	return 0;
}
