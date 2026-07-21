#include "bits/stdc++.h"
using namespace std;

int main() {
	
	int a, b;
	cin >> a >> b;
	string grid[a];
	for (int i=0; i<a; i++) cin >> grid[i];
	string sub[b];
	for (int i=0; i<b; i++) cin >> sub[i];
	
	int topl = a - b + 1;
	for (int i=0; i<topl; i++) {
		for (int j=0; j<topl; j++) {
			bool can = true;
			for (int x=0; x<b; x++) {
				for (int y=0; y<b; y++) {
					if (sub[x][y] != grid[i+x][j+y]) can = false;
				}
			}
			if (can) {
				cout << "Yes" << endl;
				exit(0);
			}
		}
	}
	cout << "No" << endl;
	
}
