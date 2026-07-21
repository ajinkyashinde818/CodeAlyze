#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <string>
#include <climits>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <numeric>
using namespace std;

int main()
{
	int n, r;
	cin >> n >> r;

	if (n >= 10)
		cout << r;
	else cout << r + 100 * (10 - n);
}
