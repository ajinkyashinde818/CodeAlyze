#include <stdio.h>
int main(){
	int a,b,c,d,f,g;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	f=a*b;
	g=c*d;
	if (f<g){
		printf("%d",g);
	}else if (g<f){
		printf("%d",f);
	}else{
		printf("%d",f);
	}
	return 0;
}
