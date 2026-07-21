#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<string> A;
	for (int i=0; i<N; i++) {
		string str;
		cin >> str;
		A.push_back(str);
	}

	vector<string> B;
	for (int i=0; i<M; i++) {
		string str;
		cin >> str;
		B.push_back(str);
	}

	for (int i=0; i<N-M+1; i++) {
		for (int j=0; j<N-M+1; j++) {
			bool unmatched = false;
			for (int k=0; k<M; k++) {
				for (int l=0; l<M; l++) {
					if (A[i+k][j+l] != B[k][l]) {
						unmatched = true;
					}
				}
			}
			if (!unmatched) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
	return 0;
}
