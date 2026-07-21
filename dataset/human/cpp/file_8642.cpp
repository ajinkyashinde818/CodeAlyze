#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <list>
#include <string>
using namespace std;
int main()
{
	int i = 0, j = 0, p = 0, q = 0, ans = 0;
	ifstream fin("input.txt");
	int N, M;
	cin >> N >> M;
	vector<vector<char> >matrix (N,vector<char>(N));

	vector<vector<char> >sub(M, vector<char>(M));
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin>>matrix[i][j];

	for (i = 0; i < M; i++)
		for (j = 0; j < M; j++)
			cin >> sub[i][j];


	for (i=0; i <= N - M; i++)
	{
		for (j=0; j <= N - M; j++)
		{
			ans = 0;
			for (p=0; p < M; p++)
			{
				for (q=0; q < M; q++)
				{
					if (matrix[i+p][j+q] == sub[p][q])
						ans++;


				}
			}
			if (ans == M*M)
			{
				cout << "Yes" << endl;
				return 0;
			}
			
				
		}
	}
	cout << "No" << endl;
	return 0;
}
