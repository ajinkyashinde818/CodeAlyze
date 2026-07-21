#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;

int main()
{
	int n, r;
	cin >> n >> r;
	if (n < 10) cout << r + 100 * (10 - n);
	else cout << r;
}
