#include <stdio.h>
#include <stdlib.h>
int main(void)
{
int a,b,i,n;
scanf("%d%d",&a,&b);
while(a!=0&&b!=0)
	{	
		for(n=0;n<a;n++)
		{
	
			
			if(n%2==0){
			for(i=0;i<b/2;i++){
				printf("#");
				printf(".");
				}
				if(b%2==1)printf("#");
			
			}
			
			else if(n%2==1)
			{
			
			for(i=0;i<b/2;i++){
				printf(".");
				printf("#");
				}
				if(b%2==1)printf(".");

			}

		puts("");
		}

		puts("");scanf("%d%d",&a,&b);
	}
return 0;
}
