#include <bits/stdc++.h>
using namespace std;
const int N = 55;

bool mat1[N][N];
bool mat2[N][N];

int main ()
{
	int n, m;
	cin >> n >> m;
	for (int i =0 ; i < n ; i ++) {
		for (int j =0 ; j < n; j ++) {
			char x;
			cin >>x;
			mat1[i][j] = (x == '#');
		}
	}
	for (int i =0 ; i < m; i ++) {
		for (int j =0 ; j < m; j ++) {
			char x;
			cin >>x;
			mat2[i][j] = (x == '#');
		}
	}
	
	for (int i = 0; i < n-m+1; i++) {
		for (int j = 0; j < n-m+1; j++) {
			
				for (int ii = 0; ii < m; ii++) {
					for (int jj = 0; jj < m; jj++) {
						if (mat1[i+ii][j+jj] != mat2[ii][jj]) {
							goto heck;
						}
					}
				}
				cout << "Yes\n";
				return 0;
				
				heck:
				continue;
		}
	}
	
	cout << "No\n";
	return 0;
}
