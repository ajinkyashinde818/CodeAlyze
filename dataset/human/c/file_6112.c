#include <stdio.h>
#define max 200001
int main(void){
	int num[max]={0},i,n,temp,min;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	temp=num[1]-num[0];
	min=num[0];
	for(i=0;i<n;i++){
		if(min>num[i]) min=num[i];
		if(temp<num[i+1]-min && n>i+1) temp=num[i+1]-min;
	}
	printf("%d\n",temp);
	return 0;
}
