#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 3e3 + 10;
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string str;
	int n;
	cin >> n;
	cin >> str;
	LL ans = 1;
	int o = 0;
	for (auto& c : str)
	{
		if (c == 'B')
		{
			if (o % 2 == 0) o++;
			else ans = ans * o-- % INF;
		}
		else
		{
			if (o % 2 == 1) o++;
			else ans = ans * o-- % INF;
		}
		if (o < 0) ans = 0;
	}
	if (o != 0) ans = 0;
	for (int i = 1; i <= n; i++) ans = ans * i % INF;
	cout << ans << endl;
	return 0;
}
