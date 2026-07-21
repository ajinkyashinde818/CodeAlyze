#include<stdio.h>

int n,i,j,a,b,k,c,x;
char s[1010][1010];

int main(){
	while(scanf("%d",&n)!=EOF){
		if(n==0)break;
		for(i=0;i<n;i++)scanf("%s",s[i]);
		k=n;x=0;
		while(k--){
			for(i=0;i<k+1;i++){
				for(j=0;j<k+1;j++){
					c=0;
					for(a=0;a<n-k;a++)for(b=0;b<n-k;b++)if(s[i+a][j+b]=='.')c++;
					if(c==(n-k)*(n-k)){
						x=n-k;
						break;
					}
				}
			}
			if(x!=n-k)break;
		}
		printf("%d\n",x);
	}
	return 0;
}
