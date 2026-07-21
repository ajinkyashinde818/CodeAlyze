#include <stdio.h>
 
char a[51][51];
char b[51][51];
 
int main(void){
	int n, m;
	int i, j, k, l, f = 0;
	
	scanf("%d %d", &n, &m);
	
	for (i = 0; i < n; i++){
		scanf("%s", a[i]);
	}
	
	for (i = 0; i < m; i++){
		scanf("%s", b[i]);
	}
	
	/*printf("a\n");
	for (i = 0; i < n; i++){
		printf("%s\n", a[i]);
	}
	
	printf("b\n");
	for (i = 0; i < m; i++){
		printf("%s\n", b[i]);
	}*/
	
	//printf("%d\n", n-m);
	
	for (i = 0; i <= n-m; i++){
		for (j = 0; j <= n-m; j++){
			if (a[i][j] == b[0][0]){
				f = 1;
				//printf("%d %d\n", i, j);
				for (k = 0; k < m; k++){
					for (l = 0; l < m; l++){
						if (a[i+k][j+l] != b[k][l]){
							f = 0;
							//printf("%d %d\n", i+k, j+l);
							break;
						}
					}
					if (f == 0) break;
				}
			}
			if (f == 1) break;
		}
		if (f == 1) break;
	}
	
	if (f) printf("Yes\n");
	else printf("No\n");
	
	return 0;
}
