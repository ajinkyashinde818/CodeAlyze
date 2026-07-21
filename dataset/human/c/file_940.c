#include<stdio.h>
int main()
{
	int a,b,c=0,i;
	scanf("%d %d",&a,&b);
	if(a==0){
		if(b>=1868&&b<=1911){
			c=(1911-b)-44;
			printf("M");
			printf("%d\n",-1*c);
		}
		else if(b>=1912&&b<=1925){
			c=(1925-b)-14;
			printf("T");
			printf("%d\n",-1*c);
		}
		else if(b>=1926&&b<=1988){
			c=(1988-b)-63;
			printf("S");
			printf("%d\n",-1*c);
		}
		else if(b>=1989&&b<=2016){
			c=(2016-b)-28;
			printf("H");
			printf("%d\n",-1*c);
		}
	}
	else if(a==1) printf("%d\n",1868+b-1);
	else if(a==2) printf("%d\n",1912+b-1);
	else if(a==3) printf("%d\n",1926+b-1);
	else if(a==4) printf("%d\n",1989+b-1);
	return 0;
}
