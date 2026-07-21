#include<stdio.h>

int main(void){
	
	int n,m[200000],i,j,c,q,p;
	
	scanf("%d",&n);
	
	for(i=0; i<n; i++){
		scanf("%d",&m[i]);
	}
	c=m[0];
	p=m[1]-m[0];
	
	for(i=0; i<n; i++){
		if(m[i]<c){
			c=m[i];
		}
		if(i != n-1){
			q=m[i+1]-c;
			if(q > p){
				p=q;
			}
		}
	}
	
	printf("%d\n",p);
	
	return 0;
}
