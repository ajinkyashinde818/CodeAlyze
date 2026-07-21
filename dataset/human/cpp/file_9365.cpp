#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int n, m, j=0;

	cin >> n >> m;
	string a[n], b[m];
	
	for(int i=0; i<n; i++) cin >> a[i];
	
	for(int i=0; i<m; i++) cin >> b[i];
	
		while(a[j].find(b[j]) != -1){
			j++;
			if(j == m) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	
	cout << "No" << endl;
	return 0;
}
