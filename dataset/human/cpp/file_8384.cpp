#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	bool ans = false;
	cin >> N >> M;

	vector<string> A(N);
	vector<string> B(M);

	for (int i = 0;i < N;i++)
		cin >> A[i];

	for (int i = 0;i < M;i++)
		cin >> B[i];

	vector<int> Pos(M);
	for (int i = 0;i < (N - M) + 1;i++)
	{
		for (int j = 0;j < (N - M) + 1;j++)
		{
			ans = true;
			for (int k = 0;k < M;k++)
			{
				Pos[k] = A[k + j].find(B[k], i);
			}

			sort(Pos.begin(), Pos.end());
			if (Pos.size() > 1)
			{
				for (int k = 1;k < M;k++)
				{
					if (Pos[k - 1] != Pos[k] || Pos[k - 1] == -1)
					{
						ans = false;
						break;
					}
				}
			}
			else
				if (Pos[0] == -1)
					ans = false;

			if (ans)
				break;
		}
		if (ans)
			break;
	}

	if (ans)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
