#include <bits/stdc++.h>

using namespace std;

int i,j,n,m;
char a[55][55],b[55][55];

int main(){
	scanf("%d%d", &n, &m);
	
	for(i = 0; i < n; i++)
	scanf("%s", a[i]);
	
	for(i = 0; i < m; i++)
	scanf("%s", b[i]);
	
	for(i = 0; i < n - m + 1; i++){
		for(j = 0; j < n - m + 1; j++){
			bool flag = 1;
			for(int ii = 0; ii < m; ii++){
				for(int jj = 0; jj < m; jj++)
				flag &= (a[i + ii][j + jj] == b[ii][jj]);
			}	
			
			if(flag)
			return 0 * printf("Yes\n");
		}
	}
	printf("No\n");
}
