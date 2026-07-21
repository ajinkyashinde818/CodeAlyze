#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include <math.h>
#include<map>
using namespace std;

int main(int argc,char** argv)
{

	int n,m;
	cin >> n >> m;
	char a[n][n];
	char b[m][m];


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

	int cnt=0;
	for(int i = 0; i <= n-m; i++){
		for(int j = 0; j <= n-m; j++){

			int tmpi = i;
			int tmpj = j;

			for(int k = 0; k < m; k++){
				for(int l = 0; l < m; l++){
					if(a[tmpi][tmpj]==b[k][l]){
						cnt++;
					}
					tmpj++;
				}
				tmpi++;
			}
			if(cnt == m*m){
				cout << "Yes" <<endl;
				return 0;
			}
			cnt = 0;
		}
	}
	cout << "No" <<endl;

	return 0;

}
