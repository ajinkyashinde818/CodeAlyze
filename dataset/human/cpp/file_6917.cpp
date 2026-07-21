#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) cin >> B[i];
	map<int, int> C;
	for (int i = 0; i < N; ++i) {
		++C[A[i]];
		++C[B[i]];
	}
	vector<int> D;
	D.insert(D.end(), A.begin(), A.end());
	D.insert(D.end(), B.begin(), B.end());
	sort(D.begin(), D.end());
	D.erase(unique(D.begin(), D.end()), D.end());
	sort(D.begin(), D.end(), [&](int i, int j) { return C[i] > C[j]; });
	if (C[D[0]] > N) {
		cout << "No" << endl;
	}
	else {
		vector<vector<int> > G(1);
		int cursum = 0;
		for (int i : D) {
			if (cursum + C[i] > N) {
				G.push_back(vector<int>());
				cursum = 0;
			}
			cursum += C[i];
			G.back().push_back(i);
		}
		int L = G.size(); // !!! S <= 3 MUST HOLD !!! //
		for (int i = 0; i < L; ++i) {
			sort(G[i].begin(), G[i].end());
		}
		string S, T;
		vector<vector<int> > TG(L);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < L; ++j) {
				if (binary_search(G[j].begin(), G[j].end(), A[i])) {
					S += 'A' + j;
				}
				if (binary_search(G[j].begin(), G[j].end(), B[i])) {
					T += 'A' + j;
					TG[j].push_back(B[i]);
				}
			}
		}
		string U;
		if (L == 2) {
			for (int i = 0; i < N; ++i) {
				U += (S[i] == 'A' ? 'B' : 'A');
			}
		}
		else if (L == 3) {
			int sa = 0, sb = 0, sc = 0, ta = 0, tb = 0, tc = 0;
			for (int i = 0; i < N; ++i) {
				if (S[i] == 'A') ++sa;
				if (S[i] == 'B') ++sb;
				if (S[i] == 'C') ++sc;
				if (T[i] == 'A') ++ta;
				if (T[i] == 'B') ++tb;
				if (T[i] == 'C') ++tc;
			}
			vector<vector<int> > mat(3, vector<int>(3));
			for (int i = 0; i <= sa + ta + sb + tb - N; ++i) {
				int g = (sa + ta + sb + tb - N) - i;
				if (sa >= i && tb >= i && sb >= g && ta >= g) {
					mat[0][1] = i;
					mat[1][0] = g;
					mat[0][2] = sa - i;
					mat[2][0] = ta - g;
					mat[1][2] = sb - g;
					mat[2][1] = tb - i;
					break;
				}
			}
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < 3; ++j) {
					if (mat[S[i] - 'A'][j] != 0) {
						U += 'A' + j;
						--mat[S[i] - 'A'][j];
						break;
					}
				}
			}
		}
		vector<int> ans;
		for (int i = 0; i < N; ++i) {
			ans.push_back(TG[U[i] - 'A'].back());
			TG[U[i] - 'A'].pop_back();
		}
		cout << "Yes" << endl;
		for (int i = 0; i < N; ++i) {
			if (i) cout << ' ';
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
