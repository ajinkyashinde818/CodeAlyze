#include<algorithm>
#include<array>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<iso646.h>
#include<queue>
#include<stack>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

#define FOR(counter,initial_value,condition) for(int counter = initial_value; counter < condition;counter++)


int main()
{
	int n, m;
	vector<string> a(50);
	vector<string> b(50);
	cin >> n >> m;
	string forFill = "";
	FOR(i, 0, 50) {
		forFill += " ";
	}
	fill(a.begin(), a.end(), forFill);
	fill(b.begin(), b.end(), forFill);
	FOR(i, 0, n) {
		cin >> a[i];
	}
	FOR(j, 0, m) {
		cin >> b[j];
	}
	bool result = false;
	FOR(i, 0, n-m+1) {
		FOR(j, 0, n - m + 1) {
			if (a[i][j] == b[0][0]) {
				result = true;
				FOR(x, 0, m) {
					FOR(y, 0, m) {
						if (a[i + x][j + y] != b[x][y]) {
							result = false;
						}
					}
				}
				if (result == true) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
}
