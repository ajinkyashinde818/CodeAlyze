#include<stdio.h>
int main(void)
{
	int a,b,c,s,i;
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%d %d",&b,&c);
		s=b%c;
			if(s==0){
				printf("%d\n",c);
			}
			else{
			printf("%d\n",s);
			}
	}
	return 0;
}
