#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<array>
#include<list>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<functional>
#include<memory>

using namespace std;

using ll = unsigned long long;

using vec = vector<int>;
using mat = vector<vec>;


int main()
{
	int N;
	cin >> N;

	if (N == 1)
	{
		cout << "Yes" << endl;
		cout << "2" << endl;
		cout << "1 1" << endl;
		cout << "1 1" << endl;
		return 0;
	}

	int SNum = 3;

	for (SNum = 3;; ++SNum)
	{
		if (SNum*(SNum - 1) / 2 == N)
		{
			break;
		}

		if (SNum*(SNum + 1) / 2 > 100000)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	
	cout << "Yes" << endl;
	cout << SNum << endl;

	mat E(SNum, vec(SNum));

	int id = 1;

	for (int i = 0; i < SNum; ++i)
	{
		for (int j = i+1; j < SNum; ++j)
		{
			if (i == j)continue;

			E[i][j] = id;
			E[j][i] = id;
			id++;
		}
	}

	for (int i = 0; i < SNum; ++i)
	{
		cout << SNum - 1 << " ";
		for (int j = 0; j < SNum; ++j)
		{
			if (i == j)continue;
			cout << E[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
