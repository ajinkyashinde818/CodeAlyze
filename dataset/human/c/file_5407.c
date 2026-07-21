#include <stdio.h>
#define MIN(x,y)	((x)<(y)?(x):(y))
int main(){
  int n,m,x,cmin=99999999;
  int c[12]={0}, a[12][12]={0};
  
  //取得
  scanf("%d%d%d", &n,&m,&x);
  for(int i=0; i<n; i++){
    scanf("%d", &c[i]);
    for(int j=0; j<m; j++){
      scanf("%d", &a[i][j]);
    }
  }
  //bit全探索
  for(int b=0; b<(1<<n); b++){
    int asum[12]={0}, csum=0;
    for(int i=0; i<n; i++){
      //本iが選択肢にある場合
      if(b & (1<<i)){
        csum += c[i];
        for(int j=0; j<m; j++){ asum[j] += a[i][j]; }
      }
    }
    //現在の本の選び方で、すべての理解度がXを超えるか
    int flag=0;
    for(int j=0; j<m; j++){
      if( asum[j] < x ){ flag=1; break; }
    }
    //現在の本の選び方でOKなので、最小金額判定
    if( !flag ){ cmin = MIN( cmin, csum ); }
  }
  //表示
  if(cmin==99999999){ printf("-1\n"); }
  else				{ printf("%d\n", cmin); }
  return 0;
}
