#include <stdio.h>
int n;
int a[25];
int b[25];
int c[25];
int ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		ans+=b[a[i]];
		if(a[i]+1==a[i+1]){
			ans+=c[a[i]];
		}
	}
	printf("%d\n",ans);
}
