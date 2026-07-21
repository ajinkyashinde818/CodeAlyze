#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <sstream>
#include <cstdlib>
using namespace std;
typedef long long ll;

int main() {
	int n, r, ans;
	cin >> n >> r;
	if(n >= 10) {
		ans = r;
	}
	else {
		ans = r + 100 * (10 - n);
	}
	cout << ans << endl;
}
