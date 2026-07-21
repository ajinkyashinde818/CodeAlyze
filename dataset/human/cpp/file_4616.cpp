#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int N, R;
	cin >> N >> R;

	auto ans = R;
	if (N < 10)
	{
		ans += 100 * (10 - N);
	}
	cout << ans << endl;
	
	return 0;
}
