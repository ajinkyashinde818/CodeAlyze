#include <stdio.h>


int main(void){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[m],b[m];
	for(int i=0;i<m;i++) scanf("%d %d",&a[i],&b[i]);
	int check[n];
	for(int i=0;i<n;i++) check[i]=0;

	for(int i=0;i<m;i++){
		if(a[i]==1){check[b[i]-1]++;}
		if(b[i]==n){check[a[i]-1]++;}
	}

	int answer=0;
	for(int i=0;i<n;i++){
		if(check[i]==2) answer=1;
	}


	if(answer==1){
		printf("POSSIBLE");
	}else{printf("IMPOSSIBLE");}
	return 0;
}
