#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i, k=1;
  int n, m;
  int *a;
  int *pat;
  int ans;

  scanf("%d %d", &n, &m);
  a=(int *)malloc((m+1)*sizeof(int));
  //何段目が壊れているかとインデックスを合わせる
  if(a == (int *)NULL){
    //エラーメッセージ
    printf("メモリ領域の確保に失敗しました。\n");
    exit(1);
  }
  a[0]=0;
  for(i=1; i<=m; i++){
    scanf("%d", &a[i]);
  }

  pat=(int *)malloc((n+1)*sizeof(int));
  //インデックスを合わせる
  if(pat== (int *)NULL){
    //エラーメッセージ
    printf("メモリ領域の確保に失敗しました。\n");
    exit(1);
  }
  pat[0]=1;

  for(i=1; i<=n; i++){
    if(k<=m-1){
      if(a[k+1]-a[k]==1){
        ans=0;
        break;
      }
    }
    if(a[k]==i){
      pat[i]=0;
      k++;
    }else{
      if(i==1){
        pat[1]=1;
      }else if(i==2){
        pat[2]=pat[1]+1;
      }else{
        pat[i]=(pat[i-1]+pat[i-2])%1000000007;
      }
      if(i==n) ans=pat[n];
    }
  }

  printf("%d\n", ans);
  free(a);
  free(pat);
  return 0;
}
