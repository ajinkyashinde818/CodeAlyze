#include <iostream>
using namespace std;

char tar[53][53], pat[53][53];

bool compare(char(*tar)[53], int N, char(*pat)[53], int M) {
	bool unfind = 0;
	for (int i = 1;i <= N;++i) {
		for (int j = 1;j <= N;++j) {
			unfind = 0;
			for (int m = 1, di = i;m <= M;++m, ++di) {
				for (int n = 1, dj = j;n <= M;++n, ++dj) {
					if (tar[di][dj] != pat[m][n]) {
						unfind = 1;
						break;
					}
				}
				if (unfind)
					break;
			}
			if (!unfind)
				return true;
		}
	}
	return false;
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1;i <= N;++i)
		for (int j = 1;j <= N;++j)
			cin >> tar[i][j];
	for (int i = 1;i <= M;++i)
		for (int j = 1;j <= M;++j)
			cin >> pat[i][j];
	if (compare(tar, N, pat, M))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	//system("pause");
	return 0;
}
