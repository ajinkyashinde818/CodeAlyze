#include <stdio.h>

int main(void){
	int a;
	scanf("%d",&a);
	int flag = 0;
	int dig;
	while(a>0){
		dig = a%10;
		if(dig == 9)flag=1;
		a /=10;
	}
	if(flag==1)printf("Yes");
	else printf("No");
	return 0;
}
