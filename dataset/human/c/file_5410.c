#include<stdio.h>
int main(void){
int n,m,x;  //n:ほんの数　//m:アルゴリズムの数
  scanf("%d%d%d",&n,&m,&x);
  int c[n];
  int a[n][m];
  for(int i=0;i<n;i++){
    	scanf("%d",&c[i]);
    	for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
        }
  }
  long money=0,min=10000000,skill[m];
 int flag2=0;
  for(int i=0;i<(1<<n);i++){
    int flag=0;
    money=0;
   	for(int l=0;l<m;l++){		//初期化
	skill[l]=0;
    }
	for(int j=0;j<n;j++){
	if(i&(1<<j)){		//j冊目の本による効果を計算
      money+=c[j];		//金額を加算
      for(int k=0;k<m;k++){
        skill[k]+=a[j][k];
      }
    }
    }//あるパターンにおける計算終了
    for(int s=0;s<m;s++){
      	if(skill[s]<x)flag=1;
    }
    if(!flag&&min>money){
      min=money;
      flag2=1;
  }
  }
    if(!flag2)printf("-1");
    else printf("%ld",min);
    return 0;
  }
