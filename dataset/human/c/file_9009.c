#include <stdio.h>

int main(void)
{
	int a;
	int x=0,count=0;
	
	while(scanf("%d",&a)&&a!=0){
		for(;a!=1;count++){
			switch(a%2){
				case 0:
					a/=2;
					break;
				case 1:
					a=a*3+1;
					break;
			}
		}
		printf("%d\n",count);
                count=0;
	}
	return 0 ;
}
