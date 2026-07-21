#include <stdio.h>

int main(void)
{
	int i[10000]={},j=0,x,d;
	
	while(1){
		scanf("%d\n",&x);
		if(x==0){
			break;
		}
		i[j]=x;
		j++;
	}
	
	for(d=0;d<=j-1;d++){
		printf("Case %d: %d\n",d+1,i[d]);
	}
		
	return 0;
}
