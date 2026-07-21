#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<string> A(N);
	vector<string> B(M);
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	for (auto i = 0; i < M; ++i)
	{
		cin >> B[i];
	}

	auto result = "No";
	for (auto i = 0; i <= N - M; ++i)
	{
		for (auto j = 0; j <= N - M; ++j)
		{
			auto isFound = true;
			for (auto k = 0; k < M; ++k)
			{
				for (auto l = 0; l < M; ++l)
				{
					if (A[i + k][j + l] != B[k][l])
					{
						isFound = false;
					}
				}
			}
			if (isFound)
			{
				result = "Yes";
			}
		}
	}

	cout << result << endl;

	return 0;
}
