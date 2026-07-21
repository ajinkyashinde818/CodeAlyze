#include<stdio.h>
int main(){
	int flag=0,i,k,l,n;
	scanf("%d",&n);
	//int a[2*n];
	for(i=0;i<n;i++){
		scanf("%d%d",&k,&l);
		if (k==l) flag++;
		else flag=0;
		if (flag==3) break;
	}
	if (flag==3) printf("Yes\n");
	else printf("No\n");
	return 0;
}
