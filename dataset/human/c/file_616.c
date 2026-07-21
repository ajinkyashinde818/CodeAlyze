#include <stdio.h>

int main(void){
	
	int m=1,n=1,dif=0,match=0;
	scanf("%d %d",&n,&m);
	
	dif = n - m;
	char a[n][51], b[m][51];

	for(int i = 0; i < n; i++){
		scanf("%s",a[i]);
	}
	for(int i = 0; i < m; i++){
		scanf("%s",b[i]);
	}
	
	for(int i = 0; i <= dif; i++){
		for(int j = 0; j <= dif; j++){
			for(int k = 0; k < m; k++){
				for(int l = 0; l < m; l++){
					if(a[i+k][j+l] == b[k][l]){ match++;}
					else { match = 0; break;}
					if(match == (m*m)) break;
				}
				if(match == 0 || match == (m*m)) break;
			}
			if(match == (m*m)) break;
		}
		if(match == (m*m)) break;
	}
	
	if(match == (m*m)) printf("Yes");
	else printf("No");
	return 0;
}
