#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000//10^12


int main(void)
{
	//変数の宣言
	int t;
	llong int a,b,c,d;
	llong int gcd;
	
	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	llong int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;
	//データの読み込み
	scanf("%d",&t);
	
	
//	printf("nは%dです\n", n);
//	printf("データの読み込み終了\n");
	//実際の処理
	
	for(i=0;i<t;i++){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		
		if(b>d){
			printf("No\n");
		}else{
			temp1=b;
			temp2=d;
		while(temp1!=0&&temp2!=0){
				if(temp1>temp2){
					temp1=temp1%temp2;
				}else{
					temp2=temp2%temp1;
				}
			}
			
			gcd=max(temp1,temp2);
			
			if(a-c>gcd){
//				printf("a=%lld,a-c=%lld,gcd=%lld,(a-c)/gcd=%lld\n",a,a-c,gcd,(a-c)/gcd);
				a=a-((a-c-1)/gcd)*gcd;
			}
//			printf("gcd=%lld,a=%lld\n",gcd,a);
			
			if(a>=b){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}
	}
	
	
	
//	printf("計算部分終了\n");
	//出力
	
	
//	printf("結果の出力終了\n");
	
	return 0;
	
}
