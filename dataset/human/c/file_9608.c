#include <stdio.h>
#include <string.h>

int main(void){
	int n, m, i, j, k, sum, keta[100], w[100], s[100][8], p[8];
	char c;
	while(1){
		scanf("%d%d%*c",&n,&m);
		if(n == 0 && m == 0) break;
		memset(keta,-1,sizeof(keta));
		memset(s,-1,sizeof(s));
		for(i = 0;i < n;i++){
			j = 0;
			for(j = 0;j < 8;j++){
				c = getchar();
				if(c != '*'){
					if(keta[i] == -1)
						keta[i] = 8 - j;
					s[i][j] = c - '0';
				}
			}
			scanf("%d%*c",&w[i]);
		}
		sum = 0;
		for(i = 0;i < m;i++){
			j = 0;
			while(j < 8){
				c = getchar();
				p[j++] = c - '0';
			}
			getchar();
			for(j = 0;j < n;j++){
				for(k = 0;k < keta[j];k++){
					if(p[7 - k] != s[j][7 - k]) break;
				}
				if(k == keta[j])
					sum += w[j];
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
