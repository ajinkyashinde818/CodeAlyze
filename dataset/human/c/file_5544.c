#include <stdio.h>
#include <string.h>

int main(void){
	int i,j,k,n,p[10000],s[10000];
	p[0]=2;p[1]=3;s[0]=2;s[1]=5;
	for(k=2,i=5;k<10000;i+=2){
		for(j=1;j<i;j++){
			if(i%p[j]==0)break;
			else if(p[j]*p[j]>i){p[k]=i;s[k]=s[k-1]+i;k++;break;}
		}
	}
	while(1){
		scanf("%d",&n);
		if(n==0)break; else printf("%d\n",s[n-1]);
	}
	return 0;
}
