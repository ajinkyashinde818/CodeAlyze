#include <stdio.h>

int main(void){
	int a,b,t,c;
	scanf("%d",&a);
	for(t=0;t<a;t++){
		scanf("%d %d",&b,&c);
		b=b%c;
		if(b==0){
			printf("%d\n",c);
		}
		else{
			printf("%d\n",b);
		}
	}

return 0;
}
