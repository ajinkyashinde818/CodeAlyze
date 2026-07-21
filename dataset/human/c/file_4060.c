#include<stdio.h>
int main()
{
	int a,b,k,i,count=0,max;
	scanf("%d %d %d",&a,&b,&k);
	if(a>b){
		max=a;
	}else{
		max=b;
	}
	for(i=max;i>0;i--){
		if(a%i==0&&b%i==0){
			count+=1;
			if(k==count){
				printf("%d\n",i);
			}
		}
	}
}
