#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <typeinfo>
#include <math.h>

using namespace std;
using ll = long long;

int main() {
	ll n, r;
	cin >> n >> r;
	if (n < 10)
		cout << r + 100 * (10 - n) << endl;
	else
		cout << r << endl;
}
