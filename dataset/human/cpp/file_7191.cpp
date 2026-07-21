#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <stack>
#include <sstream>
#include <set>
#include <cmath>
#include <functional>
#include <numeric>

using namespace std;

int main(void)
{
	vector <long long int> card;
	long long int t, n, S = 0,R = 0;
	long long int res = 2100000000;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		card.push_back(t);
		S += t;
	}

	for (int i = card.size() - 1; i > 0; i--)
	{
		S -= card[i];
		R += card[i];
		if (abs(S - R) < res)
		{
			res = abs(S - R);
		}
	}

	cout << res << endl;
	return 0;

}
