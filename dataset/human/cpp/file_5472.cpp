#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)


int main() {
	int n,r;
	cin >> n >> r;
	if (n >= 10) {
		cout << r << endl;
	} else {
		cout << r + 100 * (10 - n) << endl;
	}


	
	return 0;
}
