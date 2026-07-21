//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <bitset>

#define ll long long
#define fri(n) for(i=0;i<(n);i++)
#define frj(n) for(j=0;j<(n);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000000000//10^18
#define INFINT 2000000001//2*10^9+1
#define MOD 1000000007
#define MODANOTHER 998244353
#define PI acos(-1)

using namespace std;



int main(void)
{
	//変数の宣言
	int r,g,b,n;

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp=0;
	int temp1=0;
	int temp2=0;
	int max=0;
	int min=INFINT;
	int len=0;
	int sum=0;
	int ok=0;
	int ng=0;
	char dummy;



	//データの読み込み


	scanf("%d %d %d %d",&r,&g,&b,&n);
//	scanf_s("%d %d %d %d",&r,&g,&b,&n);


	//	scanf("%s",&s);
	//	scanf_s("%s",&s,200010);

//	scanf("%c",&dummy);
//	scanf_s("%c",&dummy);


/*	for(i=0;i<n;i++){
//		scanf("%d",&s[i]);
		scanf_s("%d",&s[i]);
	}*/

/*	for(i=0;i<n;i++){
//		scanf("%c",&t[i]);
		scanf_s("%c",&t[i]);
	}*/

	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

	for(i=0;i*r<=n;i++){
		for(j=0;i*r+j*g<=n;j++){
			if((n-i*r-j*g)%b==0){
				ans++;
			}
		}
	}

	
	//	printf("計算部分終了\n");

	//出力

	printf("%d",ans);

//C	printf("\nL=%d,R=%d,D=%d,U=%d\n",L,R,D,U);

	//	printf("結果の出力終了\n");

	return 0;
}
