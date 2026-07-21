#include <stdio.h>

int main(){
	int a,b,c;
	int ans;
	scanf("%d%d%d",&a,&b,&c);

	if(b>=c){
		printf("%d\n",b+c);
	}else if(a+b>=c){
		printf("%d\n",b+c);
	}else {
		printf("%d\n",1+a+2*b);
	}
}
