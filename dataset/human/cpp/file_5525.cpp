#include <iostream>

#include <map>
#include <string>

#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cinttypes>


using namespace std;

int main()
{
	int n, r;
	cin >> n >> r;

	if (n < 10)
	{
		r = r + (100 * (10 - n));
	}

	cout << r << endl;

	return 0;
}
