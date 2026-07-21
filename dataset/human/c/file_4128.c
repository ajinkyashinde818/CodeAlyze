#include <stdio.h>
int main(void){
	int a,b,c;
	int cont=0, valor;
	scanf("%d %d %d",&a,&b,&c);
	for(int i=100;i>0;i--){
		if(a%i==0 && b%i==0){
			cont++;
			if(cont==c){printf("%d\n", i);break;}
	}
	}
	return 0;}
