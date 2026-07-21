#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))

int main(void)
{
	//変数の宣言
	long long int n;
	long long int a[100010];
	long long int sum;
	
	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	long long int temp,temp1,temp2;
	int max,min;
	int len;
	//データの読み込み
	
	scanf("%lld",&n);
	
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	a[n]=a[0];
	
//	printf("nは%dです\n", n);
//	printf("データの読み込み終了\n");
	//実際の処理
	
	if(n==1){
		printf("YES\n");
		return 0;
	}
	
	sum=0;
	for(i=0;i<n;i++){
		sum=sum+a[i];
	}
	
	if(sum%(n*(n+1)/2)!=0){
		printf("NO\n");
		return 0;
	}else{
		temp=(sum/(n*(n+1)/2));
	}
	
	temp2=temp;
	for(i=0;i<n;i++){
		if((temp+a[i]-a[i+1])%n!=0||(temp+a[i]-a[i+1])/n<0){
			printf("NO\n");
			return 0;
		}else{
			temp2=temp2-(temp+a[i]-a[i+1])/n;
		}
	}
	
	
//	printf("計算部分終了\n");
	//出力
	
	if(temp2==0){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
//	printf("結果の出力終了\n");
	
	return 0;
	
}
