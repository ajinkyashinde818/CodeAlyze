#include <stdio.h>

int main(){
	int n,m,i,a,b,c=0,data1[200001]={0},datan[200001]={0};
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		if(a==1){
			data1[b]=1;
		}else if(b==n){
			datan[a]=1;	
		}
	}
	
	for(i=0;i<n;i++){
		if(datan[i]==1){
			if(data1[i]==1){
				printf("POSSIBLE\n");
				return 0;
			}
		}
	}
	
	printf("IMPOSSIBLE\n");
	
return 0;
}
