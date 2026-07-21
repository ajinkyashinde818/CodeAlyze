#include<stdio.h>
long long int z(int a,int b){
	long long int t;
	if(b>a){
		t=b;
		b=a;
		a=t;
	}
	while(b!=0){
	t=b;
	b=a%b;
	a=t;
}
return a;
}
int main(){
	long long int a,b,c;
	scanf("%lld%lld",&a,&b);
	c=z(a,b);
	printf("%lld",(a*b)/c);
	return 0;
}
