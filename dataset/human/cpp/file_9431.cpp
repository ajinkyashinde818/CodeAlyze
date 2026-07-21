#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
using namespace std;
int main(){
	int n, m, co = 0;
	string a[50], b[50];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> b[j];
	}
	for (int l1 = 0; l1 < n - m + 1; l1++) {
		for (int k = 0; k < n - m + 1; k++) {
			for (int l = 0; l < m; l++) {
				if (b[l] == a[k + l].substr(l1, m)) {
					co++;
				}
			}
			if (co == m) {
				cout << "Yes" << endl;
				return 0;
			}
			co = 0;
		}
	}
	cout << "No" << endl;
	return 0;

}
