#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool equal(vector<string>a, vector<string>b) {
	if (a.size() != b.size())return false;
	for (int i = 0; i < a.size(); i++) {
		if (a[i].length() != b[i].length())return false;
		for (int j = 0; j < a[i].length(); j++) {
			if (a[i][j] != b[i][j])return false;
		}
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string>a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n - m + 1; i++) {
		for (int j = 0; j < n - m + 1; j++) {
			vector<string>p(m);
			for (int k = 0; k < m; k++) {
				p[k] = a[i + k].substr(j, m);
			}
			if (equal(p, b)) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
