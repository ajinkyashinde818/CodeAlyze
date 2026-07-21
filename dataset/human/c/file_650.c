#include <stdio.h>
#include <string.h>

int main(void) {
	int n,m,flag;
	char a[50][51],b[50][51];
	
	scanf("%d %d",&n,&m);
	
	for (int i = 0;i < n;i++) {
		scanf("%s",a[i]);
	}
	for (int i = 0;i < m;i++) {
		scanf("%s",b[i]);
	}
	
	for (int i = 0;m+i <= n;i++) {
		for (int j = 0;m+j <= n;j++) {
			if (!strncmp(a[i]+j,b[0],m)) {
				flag = 1;
				for (int k = 1;k < m;k++) {
					if (strncmp(a[i+k]+j,b[k],m)) {
						flag = 0;
						break;
					}
				}
				if (flag) {
					printf("Yes\n");
					return 0;
				}
			}
		}
	}
	printf("No\n");
	
	return 0;
}
