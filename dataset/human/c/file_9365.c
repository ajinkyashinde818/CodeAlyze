#include<stdio.h>

int main(){
	
	int n,d,x;
	int i;
	char a[100];
	int ans=0;
	
	scanf("%d %d %d",&n,&d,&x);

	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	for(i=0;i<n;i++){
		if(d%a[i]==0){
			ans+=d/a[i];
		}
		else{
			ans+=(d/a[i]+1);
		}
	}

	ans+=x;
	printf("%d",ans);

	return 0;
}
