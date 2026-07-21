#include <stdio.h>
int main(){
	int ans,n,a,b,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		if(a>b){
			ans=a%b;
			if(a%b==0)ans=b;
		}
		else ans=a;
		printf("%d\n",ans);
	}
	return 0;
}
