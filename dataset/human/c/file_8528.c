#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//変数の宣言
	int n;
	int a[60];
	int maxid,minid;
	
	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	//データの読み込み
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
//	printf("nは%dです\n", n);
//	printf("データの読み込み終了\n");
	//実際の処理
	
	max=a[0];
	min=a[0];
	maxid=0;
	minid=0;
	
	for(i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
			maxid=i;
		}
		if(min>a[i]){
			min=a[i];
			minid=i;
		}
	}
	
	if(max+min>0){
		printf("%d\n",2*n-1);
		for(i=0;i<n;i++){
			printf("%d %d\n",maxid+1,i+1);
		}
		for(i=1;i<n;i++){
			printf("%d %d\n",i,i+1);
		}
	}else{
		printf("%d\n",2*n-1);
		for(i=0;i<n;i++){
			printf("%d %d\n",minid+1,i+1);
		}
		for(i=n-1;i>0;i--){
			printf("%d %d\n",i+1,i);
		}
	}
	
//	printf("計算部分終了\n");
	//出力
	
	//printf("%d\n",ans);
	
//	printf("結果の出力終了\n");
	
	return 0;
	
}
