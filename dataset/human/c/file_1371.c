#include <stdio.h>

int main(void) {
	int n,m;
	int i;
	int flag = 0;
	int iki[200000];
	int kaeri[200000];
	int a,b;
	
	scanf("%d %d",&n,&m);
	
	for(i=0;i<n;i++){
		iki[i] = 0;
		kaeri[i] = 0;
	}
	
	for(i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		if(a==1) iki[b]=1;
		if(b==n) kaeri[a]=1;
	}
	for(i=0;i<n;i++){
		if((iki[i] == 1)&&(kaeri[i] == 1)){
			printf("POSSIBLE");
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		printf("IMPOSSIBLE");
	}
	return 0;
}
