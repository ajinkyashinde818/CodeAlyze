#include <stdio.h>

int main(void) {
	int r=0,i,j,c,n,p[128];
	scanf("%d",&n);
	for(i = 1;i <= n;i++){scanf("%d",&p[i]);}
	for(i = 1;i <= n;i++){
		c = 0;
		for(j = 1;j <= n;j++){
			if(p[j] >= i){c++;}
		}
		if(c >= i){r = i;}else{break;}
	}
	printf("%d\n",r);
	return 0;
}
