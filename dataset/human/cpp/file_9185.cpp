#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <list>
#include <cstring>
#include <stack>

using namespace std;

#define mod 1000000007

int main()
{
	int n, m;
	cin >> n >> m;
	char a[51][51], b[51][51];
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
	for(int i = 0; i + m <= n; i++){
		for(int j = 0; j + m <= n; j++){
			bool include = true;
			for(int k = 0; k < m; k++){
				for(int l = 0; l < m; l++){
					if(a[i + k][j + l] != b[k][l]){
						include = false;
						k = m;
						break;
					}
				}
			}
			if(include){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
