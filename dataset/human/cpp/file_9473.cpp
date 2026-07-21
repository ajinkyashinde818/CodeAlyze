#include <iomanip>
#include <random>
#include <time.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int main()
{	
	long long int x, y, yan = 0;
	char a[55][55], b[55][55];
	cin >> x >> y;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= x; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= y; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 1; i <= x-y+1; i++) {
		for (int j = 1; j <= x-y+1; j++) {
			if (a[i][j] == b[1][1]) {
				for (int k = 1; k <= y; k++) {
					for (int l = 1; l <= y; l++) {
						if (a[i + k - 1][j + l - 1] != b[k][l]) {
							yan = 1;
							break;
						}
					}
					if (yan) {
						break;
					}
				}
				if (!yan) {
					cout << "Yes" << endl;
					return 0;
				}
				yan = 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
