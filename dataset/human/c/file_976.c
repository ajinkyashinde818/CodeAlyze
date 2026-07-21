#include<stdio.h>
int main(void)
{
	int e,y,s;
	char c;
	scanf("%d %d",&e,&y);
	if(e==0){
		c='M';
	    s=y-1867;
		if(y>=1912){
			c='T';
			s=y-1911;
		}
		if(y>=1926){
			c='S';
			s=y-1925;
		}
		if(y>=1989){
			c='H';
			s=y-1988;
		}
		printf("%c%d\n",c,s);
	}
	if(e==1){
		printf("%d\n",1867+y);
	}
	if(e==2){
	    printf("%d\n",1911+y);
	}
	if(e==3){
		printf("%d\n",1925+y);
	}
	if(e==4){
		printf("%d\n",1988+y);
	}
	return 0;
}
