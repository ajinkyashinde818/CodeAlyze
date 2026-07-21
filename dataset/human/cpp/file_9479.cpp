#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<string> imgN(N);
	vector<string> imgM(M);

	for (int i = 0; i < N; i++)
		cin >> imgN[i];

	for (int i = 0; i < M; i++)
		cin >> imgM[i];

	bool result;
	for (int i = 0; i + M <= N; i++) {
		for (int j = 0; j + M <= N; j++) {
			result = true;
			for (int w = 0; w < M && result; w++) {
				for (int h = 0; h < M && result; h++) {
					if (imgN[j + h][i + w] != imgM[h][w]) {
						result = false;
					}
				}
			}
			if(result)
				goto END_HANDLE;
		}
	}
END_HANDLE:

	cout << (result ? "Yes" : "No") << endl;

	return 0;
}
