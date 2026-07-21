#include<stdio.h>
int main(void){
	int n,p[101],i,m=0,j,c;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&p[i]);
		if(p[i]>m){
			m=p[i];
		}
	}
	if(n<m){
		m=n;
	}
	for(;;m--){
		c=0;
		for(j=1;j<=n;j++){
			if(p[j]>=m){
				c++;
			}
		}
		if(c>=m){
			break;
		}
	}
	printf("%d\n",m);
	return 0;
}
