#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	char a[n][n + 1], b[m][m + 1];

	for(int i = 0; i < n; ++i)
		scanf("%s", a[i]);
	for(int i = 0; i < m; ++i)
		scanf("%s", b[i]);

	bool flag = 1;

	/*if(n == m){
		for(int k = 0; k < n; ++k){
			for(int l = 0; l < n; ++l){
				if(a[k][l] != b[k][l]){
					flag = 0;
				}
			}
		}
	}else{*/
		for(int i = 0; i <= n - m; ++i){
			for(int j = 0; j <= n - m; ++j){
				for(int k = 0; k < m; ++k){
					for(int l = 0; l < m; ++l){
						if(a[i + k][j + l] != b[k][l]){
							flag = 0;
							break;
						}else if(l == m - 1)
							flag = 1;
					}
				if(flag == 0)
					break;
				}
			if(flag == 1)
				break;
			}
		if(flag == 1)
			break;
		}
	//}
			
	if(flag == 1)
		cout << "Yes\n";
	else 
		cout << "No\n";

	return 0;
}
