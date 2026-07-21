#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int n,m;
	cin >> n >> m;
	char a[51][51],b[51][51];
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
	int flag,i,j,k,l;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			flag=0;
			for(k=0; k<m; k++){
				for(l=0; l<m; l++){
					if(i+k>n || j+l>n)break;
					if(a[i+k][j+l]!=b[k][l]){
						flag=1;
						break;
					}
				}
				if(flag==1)break;
			}
			if(!flag){
				cout << "Yes" << endl;
				return 0;
			}
			cout << endl;
		}
	}
	cout << "No" << endl;
	return 0;
}
