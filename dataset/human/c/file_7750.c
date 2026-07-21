#include <stdio.h>

int main(void){
	
	int a,b,c,i;
	int ans;
	
	scanf("%d",&a);
	
	for(i=0;i<a;i++){
		scanf("%d %d",&b,&c);
		ans=b%c;
		if(ans==0){
			printf("%d\n",c);
		}else{
			printf("%d\n",ans);
		}
	}
	return 0;
}
