#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<stack>
#include<set>


using namespace std;


int main() {
	int N, R;
	cin >> N >> R;
	int x = 0;
	if (N < 10) {
		x = 100 * (10 - N);
	}
	cout << R + x << endl;
	return 0;
}
