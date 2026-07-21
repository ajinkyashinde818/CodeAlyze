#include<stdio.h>
int main(){
	int a,b,c=0;
	scanf("%d %d",&a,&b);
	for(int i=0;i<=a;i++){
	for(int j=0;j<=a;j++){
		if(b-i-j<=a&&b-i-j>=0){
			c++;
		}
	}
	}
	printf("%d",c);
	return 0;
}
