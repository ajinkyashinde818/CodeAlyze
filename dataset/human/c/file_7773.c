#include<stdio.h>
int main(void)
{
	int k,p,n,i,w;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d %d",&k,&p);
		if(k<p){
			w=k;
		}
		else if(k%p==0){
			w=p;
		}
			else{
				w=k%p;
			}
		printf("%d\n",w);
	}
	return 0;
}
