#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	char a[n][n], b[m][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			cin >> b[i][j];
		}
	}

	for(int i = 0; i <= n - m; i++){
		for(int j = 0; j <= n - m; j++){
			bool exist = true;
			for(int k = 0; k < m; k++){
				for(int l = 0; l < m; l++){
					if(a[i + k][j + l] != b[k][l]){
						exist = false;
					}
				}
			}
			if(exist){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
