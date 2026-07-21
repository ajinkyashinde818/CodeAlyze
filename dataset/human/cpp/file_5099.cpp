#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include <random>
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int N, R;
	cin >> N >> R;
	if (N >= 10) {
		cout << R;
	}
	else {
		cout << R + 100 * (10 - N);
	}
}
