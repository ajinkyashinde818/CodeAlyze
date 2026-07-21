#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<char>> A(N, vector<char>(N));
	vector<vector<char>> B(M, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A.at(i).at(j);
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cin >> B.at(i).at(j);
		}
	}

	bool exist = false;
	for (int y1 = 0; y1 <= N - M; y1++) {
		for (int x1 = 0; x1 <= N - M; x1++) {
			bool match = false;

			if (A.at(y1).at(x1) == B.at(0).at(0)) {
				bool match = true;

				for (int y2 = 0; y2 < M; y2++) {
					for (int x2 = 0; x2 < M; x2++) {
						if (B.at(y2).at(x2) != A.at(y1 + y2).at(x1 + x2)) {
							match = false;
							break;
						}
					}
				}

				if (match) {
					exist = true;
					break;
				}
			}
		}
	}

	if (exist) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}
