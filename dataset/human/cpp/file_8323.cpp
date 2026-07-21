#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;
int main()
{
	long long int x, y;
	char a[55][55], b[55][55];
	cin >> x >> y;
	bool f = 0;
	for (int i = 0; i < x; i++) for (int j = 0; j < x; j++) cin >> a[i][j];
	for (int i = 0; i < y; i++) for (int j = 0; j < y; j++) cin >> b[i][j];
	for (int i = 0; i <= x - y; i++) {
		for (int j = 0; j <= x - y; j++) {
			if (a[i][j] == b[0][0]) {
				for (int k = 0; k < y; k++) {
					for (int l = 0; l < y; l++) {
						if (a[i + k][j + l] != b[k][l]) {
							f = 1;
							break;
						}
					}
					if (f)break;
				}
				if (!f) {
					cout << "Yes" << endl;
					return 0;
				}
				f = 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
