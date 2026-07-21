#include<stdio.h>
int main(void)
{
	int n,p[100],i,j,x,y[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	
	for(i=n;i>0;i--){
		x=0;
		for(j=0;j<n;j++){
			if(i<=p[j]){
				x++;
			}
		}
		if(x>=i){
			break;
		}
	}
	printf("%d\n",i);
	return 0;
}
