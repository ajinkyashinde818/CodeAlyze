#include <stdio.h>

int main(){
	int h[100], w[100];
	int i=0;
	while(1){
		scanf("%d%d", &h[i], &w[i]);
		if(h[i]==0 && w[i]==0){
			break;
		}
		i++;
	}
	
	int n=i;
	int j, k;
	for(i=0;i<n;i++){
		for(j=0;j<h[i]; j++){
			for(k=0;k<w[i];k++){
				if((j+k)%2==0){
					printf("#");
				}else{
					printf(".");
				}
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
