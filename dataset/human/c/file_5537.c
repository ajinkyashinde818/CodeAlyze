#include <stdio.h>
int is_prime(int n){
	int i;
	for(i=2;i*i<=n;i++){
		if(!(n%i))
			return 0;
	}
	return 1;
}
int main(void){
	int i,n,c,s;
	while(scanf("%d",&n),n){
		s=c=0;
		for(i=2;;i++){
			if(is_prime(i)){
				s+=i;
				c++;
			}
			if(c==n)
				break;
		}
		printf("%d\n",s);
	}
	return 0;
}
