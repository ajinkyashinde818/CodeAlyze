#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
#include <queue>
#include <numeric>
#include <ctype.h>
#include <limits>
#include <iomanip>

#define rep(i,n) for (int i = 0; i < n; i++)
#define all(x) (x).begin(),(x).end()
using namespace std;

typedef long long ll;

int main()
{
	int n, r;
	cin >> n >> r;
	int i;
	if (n >= 10)i = r;
	else i = r + 100 * (10 - n);
	cout << i;
	return 0;
}
