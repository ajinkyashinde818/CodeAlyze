#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <memory>

//#define int long long

using namespace std;

void Main()
{
	int n = 0;
	int r = 0;
	cin >> n >> r;

	int internal = 0;

	if (n >= 10) {
		internal = r;
	}
	else {
		internal = r + 100 * (10 - n);
	}

	cout << internal << endl;
}

int32_t main()
{
	Main();
	return 0;
}
