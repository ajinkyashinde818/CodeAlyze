#include<stdio.h>
/*ALDS1_1_D*/

int main(void)
{
	int n;
	int exchange_origin[200000]={0};
	int exchange_gain;
	int exchange_gain_max;
	int i,j; 
	int min;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&exchange_origin[i]);
	}
	
	min=exchange_origin[0];
	exchange_gain_max=exchange_origin[1]-exchange_origin[0];
	
	for(i=0;i<n-1;i++){
		if(exchange_origin[i]>min)continue;
		min=exchange_origin[i];
		for(j=i+1;j<n;j++){
			exchange_gain=exchange_origin[j]-min;
			if(exchange_gain_max<exchange_gain){
				exchange_gain_max=exchange_gain;
			}
		}
	}
	
	printf("%d\n",exchange_gain_max);
}
