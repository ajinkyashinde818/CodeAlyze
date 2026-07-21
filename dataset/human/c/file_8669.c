#include <stdio.h>


int main(){
	
	int n,a[100000],i,m=1,count=0;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	while(count<=n){
		count=count+1;
		m = a[m-1];
		if(m==2){break;}
	}
	
	if(count==n+1)printf("-1\n");
	else printf("%d\n",count);
	
	return 0;
}
