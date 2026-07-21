#include <stdio.h>
int main(void){
	int p_vol,day,remain,sum=0,l,weight;
	scanf("%d",&p_vol);
	scanf("%d %d",&day,&remain);
	for (int i = 0; i < p_vol; ++i){
		scanf("%d",&weight);
		l=(day-1)/weight;
		sum=sum+l+1;
	}
	sum=sum+remain;
	printf("%d\n",sum);
}
