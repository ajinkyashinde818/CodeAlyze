#include<stdio.h>
int main()
{
	int a,b,i,n;
	while(1){
	scanf("%d %d",&a,&b);
	if(a==0&&b==0)
		break;
	for(i=1;i<=a;i++){
		if(i%2==1){
		for(n=1;n<=b;n++){
			if(n%2==1)
			   printf("#");
			else 
				printf(".");
			}
		}
		else {
			for(n=1;n<=b;n++){
			if(n%2==0)
			   printf("#");
			else 
				printf(".");
			}
		}
	printf("\n");
	}
	printf("\n");
	}
	return 0;
}
