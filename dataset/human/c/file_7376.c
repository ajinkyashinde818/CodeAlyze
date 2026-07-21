#include<stdio.h>
int main()
{
	int i=0,j,x[10000];
	while(1){
		scanf("%d",&x[i]);
		if(x[i]==0){
			break;
		}
		i++;
	}
	for(j=0;i>=j;j++){
		if(x[j]==0){
			break;
		}
		printf("Case %d: %d\n",j+1,x[j]);
	}
	return 0;
}
