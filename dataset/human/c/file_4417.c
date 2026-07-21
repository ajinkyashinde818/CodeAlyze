#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int max=0;
	int rec=0;
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		if (x==y) rec++;else rec=0;
		if (max<rec) max=rec;
	}
	if (max>=3) printf("Yes");else printf("No");
}
