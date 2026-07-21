#include<stdio.h>
int main(void)
{
	int a,b,x[1001],i,j,S;
	scanf("%d %d",&a,&b);
	for(i=0;i<a;i++){
		scanf("%d",&x[i]);
	}
	for(i=1;i<=b;i++){
		for(j=0;j<a-1;j++){
			if(x[j]%i>x[j+1]%i){
				S=x[j];
				x[j]=x[j+1];
				x[j+1]=S;
			}
		}
	}
	for(i=0;i<a;i++){
		printf("%d\n",x[i]);
	}
	return 0;
}
