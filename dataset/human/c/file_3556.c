#include <stdio.h>

int main(void)
{
	int ans,sco[100],i;
	int max = 1,num = 0;
	
	scanf("%d",&ans);
	
	for(i = 0;i < ans;i++){
		scanf("%d",&sco[i]);
	}
	while(i-1 < ans){
		if(max <= sco[i-1]){
			num++;
		}
		if(max == num){
			i = 0;
			max++;
			num = 0;
		}
		i++;
	}
	
	printf("%d\n",max-1);
	
	return(0);
}
