#include<stdio.h>

int main(void)
{
	int n,box1,box2,minv,maxv,i,j;
	scanf("%d",&n);
	scanf("%d",&box1);
	scanf("%d",&box2);
	if(box1<box2) minv=box1;//初期値設定
	else minv=box2;
	maxv=box2-box1;
	for(i=1;i<n-1;i++){
		scanf("%d",&box1);
		if(maxv<box1-minv) maxv=box1-minv;//iまでの最大の差を保存
		if(minv>box1) minv=box1;//iまでの最小値を保存
	}
	
	printf("%d\n",maxv);
	return 0;
}
