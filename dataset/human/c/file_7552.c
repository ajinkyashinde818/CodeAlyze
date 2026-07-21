#include <stdio.h>

int main()
{
	int a[10000];
	int i,k;
	
	i=0;
	
	while(1){
	scanf("%d",&a[i]);
	if(a[i]==0){
		break;
		return 0;
	}
	i++;
	}
	
	for(k=0;k<i;k++){
		printf("Case %d: %d\n",k+1,a[k]);
	}
	
return 0;
}
