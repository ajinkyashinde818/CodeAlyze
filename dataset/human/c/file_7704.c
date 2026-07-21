#include<stdio.h>

#define box 10000

int main()
{
	int i,num=0;

	int data[box];

	while(1){
		scanf("%d",&i);
		if(i==0) break;
		data[num]=i;
		num++;
	}
	
	for(i=0;i<num;i++) printf("Case %d: %d\n",i+1,data[i]);

	return 0;
}
