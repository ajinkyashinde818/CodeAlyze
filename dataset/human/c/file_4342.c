#include<stdio.h>
int main(){
	int n,a[105],b[105],f=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n-2;i++) if(a[i]==b[i]&&a[i+1]==b[i+1]&&a[i+2]==b[i+2]) f=1;
	if(f) printf("Yes");
	else printf("No");
	return 0;
}
