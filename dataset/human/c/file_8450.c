#include<stdio.h>
int main(void){
	int s,b,copy;
	int i,j;
	int a[200];
	scanf("%d%d",&s,&b);
	for(i=0;i<s;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=b;i++){
		for(j=0;j<s-1;j++){
			if(a[j]%i>a[j+1]%i){
				copy=a[j];
				a[j]=a[j+1];
				a[j+1]=copy;
			}
		}
	}
	for(i=0;i<s;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
