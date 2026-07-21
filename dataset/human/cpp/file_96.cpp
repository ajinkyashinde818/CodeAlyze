#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

void Diverta2019_B()
{
	int N;
	vector<int> ball(3);
	cin >> ball[0] >> ball[1] >> ball[2] >> N;
	sort(ball.begin(), ball.end(), greater<int>());

	int ct = 0;
	int m = N / ball[0];
	for (int i = 0; i <= m; ++i)
	{
		int r1 = N - ball[0] * i;
		
		int el = r1 / ball[1];
		for (int j = 0; j <= el; ++j)
		{
			int r2 = r1 - ball[1] * j;
			if (r2 % ball[2] == 0)
				++ct;
		}
	}
	cout << ct << endl;
}

int main()
{
	Diverta2019_B();
	return 0;
}
