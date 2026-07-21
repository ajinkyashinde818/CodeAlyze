#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void){
  int n;
  scanf("%d",&n);

  int a[20];
  int b[20];
  int c[19];

  for(int i = 1; i <= n; i++){
	  scanf("%d",&a[i]);
  }
  for(int i = 1; i <= n; i++){
	  scanf("%d",&b[i]);
  }
  for(int i = 1; i < n; i++){
	  scanf("%d",&c[i]);
  }

  int ans = 0;
  int now_ind = 0;
  int prev_ind = 0;

  /*満足度の集計*/
  for(int i = 1; i <= n; i++){
	  prev_ind = a[i-1];
	  now_ind = a[i];
	  //Bの満足度を加算
	  ans += b[now_ind];

	  /* Cの条件
	   * そのとき追加
	   * */
	  int judge_c = (i > 1) && (now_ind - prev_ind == 1);
	  if(judge_c){
		  ans += c[prev_ind];
	  }
  }
  printf("%d\n", ans);


  return 0;
}
