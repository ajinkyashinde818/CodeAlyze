#include <bits/stdc++.h>
using namespace std;

const int N = (int) 1e5 + 5;

int n;
vector <int> p[450], group[450];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int k = sqrt(2 * n);
	if ((k - 1) * k < 2 * n) k++;
	if ((k - 1) * k > 2 * n) k--;
	if ((k - 1) * k != 2 * n) return cout << "No", 0;
	k--;
	cout << "Yes\n";
	int num = 0;
	for (int i = 1; i <= k; i++) {
		p[i].resize(i + 1);
		for (int j = 1; j <= i; j++) p[i][j] = ++num;
	}
	for (int c = 1; c <= k; c++) {
		for (int r = c; r <= k; r++) group[c].push_back(p[r][c]);
		for (int c2 = c - 1; c2 >= 1; c2--) group[c].push_back(p[c][c2]);	
	}
	num = 0;
	for (int i = 1; i <= k; i++) { 
		num += i;
		group[k + 1].push_back(num); 
	}
	cout << k + 1 << "\n";
	for (int i = 1; i <= k + 1; i++) {
		cout << group[i].size() << " ";
		for (int j = 0; j < group[i].size(); j++) cout << group[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
