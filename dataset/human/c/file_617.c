#include <stdio.h>
#include <string.h>

int main(void){
	int n, m, flag = 1;
	char a[51][51], b[51][51];

	scanf("%d%d", &n, &m);
	for(int i=0; i < n; i++)
		scanf("%s", a[i]);
	for(int i=0; i < m; i++)
		scanf("%s", b[i]);

	for(int i=0; i < n-m+1; i++) {
		for(int j=0; j < n-m+1; j++) {
			for(int k=0; k < m; k++) {
				for(int l=0; l < m; l++) {
					if(a[i+k][j+l] != b[k][l])
						flag = 0;
				}
			}
			if(flag) {
				printf("Yes");
				return 0;
			}
			flag = 1;
		}
	}
	printf("No");

	return 0;
}
