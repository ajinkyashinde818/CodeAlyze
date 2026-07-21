#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <deque>

using namespace::std;

int ri()
{
	int x;
	scanf("%d", &x);

	return x;
}

int64_t ri64()
{
	int64_t x;
	scanf("%lld", &x);

	return x;
}

void wi(int x)
{
	printf("%d\n", x);
}

void wvi(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
	printf("\n");
}

void dbg(string &str, int x)
{
	cout << str << ": ";
	wi(x);
}

void dbg(string &str, vector<int> &x)
{
	cout << str << ": ";
	wvi(x);
}

int main()
{
	int N = ri();	
	
	int n = 8 * N + 1;
	int m = (int) (sqrt((double) n));
	
	if (n != (m * m))	
	{
		cout << "No" << endl;
		return 0;
	}	

	int k = (m + 1) / 2;

	vector<vector<int> > A(k);
	
	int c = 1;
	for (int i = 0; i < k; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			A[i].push_back(c);
			A[j].push_back(c);

			c++;
		}
	}

	cout << "Yes" << endl;
	cout << k << endl;
	
	for (int i = 0; i < k; i++)
	{
		cout << A[i].size() << " ";
		for (int j = 0; j < A[i].size(); j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	return 0;
}
