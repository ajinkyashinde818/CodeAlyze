#include<stdio.h>
int main()
{
	int r,g,b,n;
	int counter=0;
	int i,j,k;
	scanf("%d %d %d %d",&r,&g,&b,&n);
	for(i=0;i<=n/r;i++){
		for(j=0;j<=(n-r*i)/g;j++){
			if((n-r*i-j*g)%b==0){
				counter+=1;
			}
		}
	}
	printf("%d",counter);
}
