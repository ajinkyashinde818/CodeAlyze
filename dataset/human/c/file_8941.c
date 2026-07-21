#include<stdio.h>
int main(void)
{
	int a,s,d;
	scanf("%d",&a);
	while(a!=0){
	s=0;
		while(a!=1){
			if(a%2==0){
				a=a/2;
				s++;
			}
			else{
				a=a*3+1;
				s++;
			}
		}
		printf("%d\n",s);
	scanf("%d",&a);
	}
	return 0;
}
