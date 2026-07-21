#include <iostream>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	char a[n][n];
	char b[m][m];


	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<m; j++){
			cin >> b[i][j];
		}
	}

	bool ans=1;

	for(int i=0; i<=n-m; i++){
		for(int j=0; j<=n-m; j++){
			ans=1;
			for(int k=0; k<m; k++){
				for(int p=0; p<m; p++){
					if(a[i+k][j+p]!=b[k][p]){
						ans=0;
						k=n;
						break;
					}
				}
			}
			if(ans==1){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}

	cout << "No" << endl;
	return 0;
}
