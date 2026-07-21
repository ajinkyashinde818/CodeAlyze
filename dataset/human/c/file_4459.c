#include <stdio.h>
int main(void){
	int n,da[100],db[100],i,j,f=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&da[i]);
		scanf("%d",&db[i]);
	}
	
	for(i=0;i<n;i++){
		if(da[i]==db[i]){
			f++;
		}else{
			f=0;
		}
		if(f==3){
			break;
		}
	}
	if(f==3){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
