#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int main() {
	int N, M,c=0;
	char S[50][50], T[50][50];
	bool ans = false;
	cin >> N >> M;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)cin >> S[i][j];
	for (int i = 0; i < M; i++)for (int j = 0; j < M; j++)cin >> T[i][j];
	for (int i = 0; i < N-M+1; i++)
	{
		for (int j = 0; j < N-M+1; j++)
		{
			bool flag = false;
			c = 0;
			for (int k = 0; k < M; k++)
			{
				for (int l = 0; l < M; l++)
				{
					if (T[k][l] == S[k + i][l + j]) {
						flag = true;
						c++;
					}
					else flag = false;
					if (!flag)break;
					if (c == M*M)ans = true;
					if (ans)break;
				}
				if (!flag)break;
				if (ans)break;
			}
			if (ans)break;
		}
		if (ans)break;
	}
	cout << (ans ? "Yes" : "No");
}
