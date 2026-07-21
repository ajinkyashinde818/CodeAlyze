#include<stdio.h>
int main(){
	int k,p,n,c,a;
	scanf("%d",&n);
	for(c=1;c<=n;c++){
		scanf("%d %d",&k,&p);
		if(k%p==0){
			a=p;
		}
		else{
			a=k%p;
		}
		printf("%d\n",a);
	}
	return 0;
}
