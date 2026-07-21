#include <stdio.h> 
int main(){
	int n;
	int a[100005];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int nx=1;int cn=0;
	for(int i=1;i<=n;i++){
		nx=a[nx];cn++;
		if(nx==2)break;
	}
	if(nx==2)printf("%d",cn);
	else printf("-1");
	return 0;
}
