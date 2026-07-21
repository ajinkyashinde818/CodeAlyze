#include <stdio.h>

int main(void)
{
	int p[10000],q[10000],t,a=0,tt,ttt;p[0]=1;q[0]=1;
	while(p[a] != 0 || q[a] !=0){
		a++;
		scanf("%d %d",&p[a],&q[a]);
		}
	for(t=1;t<a;t++){
		for(tt=1;tt<=p[t];tt++){
			for(ttt=1;ttt<=q[t];ttt++){
				if((tt+ttt)%2==0){
				    printf("#");}
				else{
					printf(".");}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
