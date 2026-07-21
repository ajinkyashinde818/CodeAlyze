#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
typedef vector<int> VI;
typedef vector<VI> VVI;


int main() {
	int N;
	cin >> N;
	int sq = sqrt(2*N);
	if (sq * (sq+1) == 2*N) {
		cout << "Yes" << endl;
		sq++;
		VVI V(sq);
		cout << V.size() << endl;
		int idx = 0;
		for (int i = 0; i < sq; ++i) {
			for (int j = i + 1; j < sq; ++j) {
				V[i].push_back(idx);
				V[j].push_back(idx);
				idx++;
			}
		}
		for (int i = 0; i < sq; ++i) {
			cout << V[i].size() << " ";
			for (int j = 0; j < V[i].size(); ++j) {
				cout << V[i][j]+1 << " ";
			}
			cout << endl;
		}
	} else {
		cout << "No" << endl;
	}

	return 0;
}
