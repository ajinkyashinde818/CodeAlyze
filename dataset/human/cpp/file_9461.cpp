#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;

int N, M;
vector<string> partTemp(int, int, vector<string>);

int main()
{
	cin >> N;
	cin >> M;
	vector<string> A(N);
	vector<string> B(M);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> B[i];
	}
	
	for (int i = 0; i + M -1 < N ; i++)
	{
		for (int j = 0; j + M - 1 < N; j++)
		{
			vector<string> sub = partTemp(j, i, A);
			if (B==sub)
			{
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}

vector<string> partTemp(int dx, int dy, vector<string> A)
{
	vector<string> part(M);
	for (int i = dy; i < dy+M; i++)
	{
		part[i-dy]=A[i].substr(dx, M);
	}
	return part;
}
