#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool b[229028];
int n, m;
vector<int>l;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)b[i] = false;
	for (int i = 0; i < m; i++){
		int a; cin >> a;
		l.push_back(a);
	}
	for (int i = 1; i <= m; i++) {
		if (!b[l[m - i]])cout << l[m - i] << endl;
		b[l[m - i]] = true;
	}
	for (int i = 1; i <= n; i++)if (!b[i])cout << i << endl;
}
