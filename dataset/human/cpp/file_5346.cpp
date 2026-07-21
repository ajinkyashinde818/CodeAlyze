#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue> 
 
using namespace std;
 
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N, R;

	cin >> N >> R;

	if(N < 10) {
		cout << R + 100 * (10 - N) << endl;
	} else {
		cout << R << endl;
	}
}
