#include<stdio.h>
int main(void){
	int data[10000];
	int num,i=0,s=0,a=1;
	while(a!=0){
		scanf("%d",&num);
		if(num==0)
			break;
		data[i]=num;
		i++;
		s++;
	}
	for(i=0;i<s;i++){
		printf("Case %d: %d\n",i+1,data[i]);
	}
	return 0;
}
