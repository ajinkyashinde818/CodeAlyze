#include<stdio.h>

int main(){
	int a,b=200000,i,c,sum=0;
	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%d",&c);
		if(i==1){
			sum=c-b;
			if(b>c)b=c;
			continue;
		}
		if(i==0){
			b=c;
			continue;
		}
		if(sum<c-b){
			sum=c-b;
		}
		if(b>c)b=c;
	}
	printf("%d\n",sum);
	return 0;
}
