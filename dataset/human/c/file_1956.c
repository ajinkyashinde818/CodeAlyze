#include <stdio.h>
int main(){
	int n,ans=0;
	int a[20]={};
	int b[20]={};
	int c[19]={};
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n-1; i++)
		scanf("%d", &c[i]);
	for (int i = 0; i < n; i++){
		ans+=b[a[i]-1];
		if(i>0&&a[i]==a[i-1]+1){
			ans+=c[a[i-1]-1];
		}
	}
	printf("%d\n", ans);
	return 0;
}
