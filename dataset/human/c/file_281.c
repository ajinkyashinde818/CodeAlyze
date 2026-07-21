#include <stdio.h>

int main(void)
{
	long long a,b[100010],i,c=0,d=1000000000,e=0,f=0;
	scanf("%lld",&a);
	for(i=0;i<a;i++){
		scanf("%lld",&b[i]);
		if(b[i]<0){
			c++;
			b[i]=b[i]*-1;
		}
		if(b[i]==0) f=1;
		if(b[i]<d) d=b[i]; 
		e=e+b[i];
	}
	if(f==1){
		printf("%lld",e);
	}else if(c%2==0){
		printf("%lld",e);
	}else{
		printf("%lld",e-d*2);
	}
	return 0;
}
