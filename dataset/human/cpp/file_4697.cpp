#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
typedef long long ll;

using namespace std;

int main()
{
	int n, r;

	cin>>n>>r;

	if (n >= 10) {
		cout << r;
	} else {
		cout << r + 100 * (10 - n);
	}
	return 0;
}
