#include <iostream>
using namespace std;

int n, m;
int e[200000];

int main() {
	int i;
	
	cin >> n >> m;
	for (i = 0; i < m; i++) cin >> e[i];
	
	static bool used[200001] = {false};
	for (i = m - 1; i >= 0; i--) {
		if (!used[e[i]]) {
			used[e[i]] = true;
			cout << e[i] << endl;
		}
	}
	for (i = 1; i <= n; i++) {
		if (!used[i]) cout << i << endl;
	}
	return 0;
}
