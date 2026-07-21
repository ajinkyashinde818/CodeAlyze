#include <stdio.h>
int main(void){
	long long q,p,n,l,r;
	char c;
	scanf("%d",&q);
	l=r=0;
	while(q--){
		scanf("%lld %c %lld",&p,&c,&n);
		if(c=='('){
			l+=n;
		}
		else{
			r+=n;
		}
		printf("%s\n",l==r?"Yes":"No");
	}
	return 0;
}
