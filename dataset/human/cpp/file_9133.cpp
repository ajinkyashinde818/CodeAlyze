#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<iomanip>
#include<map>
#include<fstream>
#include<queue>

using namespace std;

int n, m;
int a[51][51] = { 0 };
int b[51][51] = { 0 };
char buf[51];


bool search(int x, int y)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (a[x + i][y + j] != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main()
{

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> buf;
		for (int j = 0; j < n; j++) {
			a[i][j] = buf[j];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> buf;
		for (int j = 0; j < m; j++) {
			b[i][j] = buf[j];
		}
	}

	bool flag = false;
	for (int i = 0; i <= n - m; i++) {
		for (int j = 0; j <= n - m; j++) {
			if (search(i, j) == true) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
