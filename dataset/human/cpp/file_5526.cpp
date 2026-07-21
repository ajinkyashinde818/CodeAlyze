#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int N;
	int R;
	cin >> N>>R;
	if (N < 10) {
		cout << R + 100 * (10 - N) << endl;
	}
	else {
		cout << R << endl;
	}
}
