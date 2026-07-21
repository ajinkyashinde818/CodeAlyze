#include<stdio.h>
int main(void)
{
	int e,y;
	char a[5]="MTSH";
	scanf("%d %d",&e,&y);
	if(e==0){
		y=y-1867;
		if(y<45) e=0;
		else if(y<59){
			e=1; y=y-44;
		}
		else if(y<122){
			e=2; y=y-58;
		}
		else{
			e=3; y=y-121;
		}
		printf("%c%d\n",a[e],y);
	}
	else{
		if(e==1) y=1867+y;
		else if(e==2) y=1911+y;
		else if(e==3) y=1925+y;
		else y=1988+y;
		printf("%d\n",y);
	}
	return 0;
}
