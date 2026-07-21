#include<stdio.h>
int main(void)
{
	int i,j,a[10000];
	i=1;
	while(1){
		scanf("%d",&a[i]);
		if(a[i]==0){
			break;
		}
		i++;
	}
	j=i;
	i=1;
	while(j>i){
		printf("Case %d: %d\n",i,a[i]);
		if(a[i]==0){
			break;
		}
		i++;
	}
	return 0;
}
