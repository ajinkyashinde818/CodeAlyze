// g++ -std=gnu++1y -O2 main.cpp

#include <cstdio>
#include <vector>
#include <set>

#include <map>
#include <unordered_map>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <climits>

using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int N, R;
	cin >> N >> R;

	if (N >= 10) {
		cout << R << endl;
	} else {
		cout << (R + 100 * (10 - N)) << endl;
	}

	return 0;
}
