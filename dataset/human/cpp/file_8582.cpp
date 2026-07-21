//#include "pch.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

//#define int ll

using namespace std;


signed main(void)
{
	//変数の宣言
	int n,m;
	int h,w;
	char a[60][60];
	char b[60][60];

	//よく使う変数
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp=0;
	int temp1=0;
	int temp2=0;
	int temp3=0;
	static int vec[100010];
	int max=0;
	int min=INFINT;
	int len=0;
	int sum=0;
	int ok=0;
	int ng=0;
	char dummy;
	static char stemp[100010];
	
	//データの読み込み


	scanf("%d %d",&n,&m);
//	scanf_s("%d %d",&n,&m);


//	scanf("%s",&s);
//	scanf_s("%s",&s,1000010);


	for(i=0;i<n;i++){
		scanf("%s",&a[i]);
//		scanf_s("%s",&a[i],60);
	}

	for(i=0;i<m;i++){
		scanf("%s",&b[i]);
//		scanf_s("%s",&b[i],60);
	}

/*	//scanf("%c",&dummy);
	scanf_s("%c",&dummy);
	for(i=0;i<n;i++){
//		scanf("%c",&s[i]);
		scanf_s("%c",&s[i]);
	}*/


/*	for(i=0;i<3;i++){
//		scanf("%s",&s);
		scanf_s("%s",&s[i],100010);
	}*/


	//	printf("nは%dです\n", n);
	//	printf("データの読み込み終了\n");
	//実際の処理

//	clock_t start=clock();

	flag=0;
	for(i=0;i<=n-m;i++){
		for(j=0;j<=n-m;j++){
			temp=1;
			for(k=0;k<m;k++){
				for(l=0;l<m;l++){
					if(a[i+k][j+l]!=b[k][l]){
						temp=0;
					}
				}
			}
			if(temp==1) flag=1;
		}
	}

	if(flag==0){
		printf("No");
	}else{
		printf("Yes");
	}

//	clock_t end=clock();

	//	printf("計算部分終了\n");

	//出力
	
	//printf("%d",(d[i-1][j-1]+1)/2);

//	printf("time=%lf",(double)(end-start)/CLOCKS_PER_SEC);
	//	printf("結果の出力終了\n");

	return 0;
}
