#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long N, L, cnts; string S[100009]; vector<int>x[100009], M;

void add(string V) {
	int cx = 0;
	for (int i = 0; i < V.size(); i++) {
		if (V[i] == '0') {
			if (x[cx][0] == -1) { x[cnts] = vector<int>{ -1,-1 }; x[cx][0] = cnts; cnts++; }
			cx = x[cx][0];
		}
		else {
			if (x[cx][1] == -1) { x[cnts] = vector<int>{ -1,-1 }; x[cx][1] = cnts; cnts++; }
			cx = x[cx][1];
		}
	}
}
void dfs(int pos, int depth) {
	for (int i = 0; i < x[pos].size(); i++) {
		if (x[pos][i] == -1) M.push_back(depth + 1);
		else dfs(x[pos][i], depth + 1);
	}
}
long long val(long long v) {
	v++;
	for (int i = 0; i < 63; i++) {
		if (v % (1LL << i) != 0) return (1LL << i) / 2;
	}
	return -1;
}

int main() {
	cin >> N >> L; x[0] = vector<int>{ -1,-1 }; cnts = 1;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
		add(S[i]);
	}
	dfs(0, 0);
	long long grundy = 0;
	for (int i = 0; i < M.size(); i++) {
		if (M[i] > L) continue;
		grundy ^= val(L - M[i]);
	}
	if (grundy == 0) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	return 0;
}
