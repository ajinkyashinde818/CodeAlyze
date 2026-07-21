#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m;
char a[55][55], b[55][55];
int cont;
int main(){
	while(~scanf("%d %d", &n, &m)){
		cont = 0;
		bool flag = false;
		for(int i = 1; i <= n; i++)
			scanf("%s", a[i] + 1);
		for(int i = 1; i <= m; i++)
			scanf("%s", b[i] + 1);
		for(int i = 1; i <= n - m + 1; i++){
			for(int j = 1; j <= n - m + 1; j++){
				cont = 0;
				for(int k = 1; k <= m; k++)
					for(int l = 1; l <= m; l++)
						if(a[i + k - 1][j + l - 1] == b[k][l]) cont++;
				if(cont == m * m) flag = true;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
