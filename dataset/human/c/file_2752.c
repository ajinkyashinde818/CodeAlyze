#include <stdio.h>

int main(void)
{
	int l,m,n,K,S,num=0;
	scanf("%d%d",&K,&S);

	for(l=0;l<=K;l++)
		for(m=l;m<=K;m++)
			for(n=m;n<=K;n++){
				if(l+m+n==S){
					if(l==m&&m==n){
						num++;
					}else if(l!=m&&l!=n&&m!=n){
						num+=6;
					}else{
						num+=3;
					}
				}
			}
	
	printf("%d\n",num);
	return 0;
}
