#include<stdio.h>
int main(void)
{
	int n,p[100],i,j,x;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	for(i=0;;i++){
		x=0;
		for(j=0;j<n;j++){
			if(p[j]>=i){
				x++;
			}
		}
		if(x<i){
			break;
		}
	}
	printf("%d\n",i-1);
	return 0;
}
