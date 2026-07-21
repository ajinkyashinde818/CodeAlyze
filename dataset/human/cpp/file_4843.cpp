#include"bits/stdc++.h"
#include<iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(void) {
	int n,r;

	cin >> n>>r;

	if (n>=10) {
		cout << r << endl;
	}
	else {
		cout << r+100*(10-n) << endl;
	}

	return 0;
}
