#include<stdio.h>
#define rep(i,n) for(int i=0; i<n; ++i)
  

  int a[12][12];

int min(int a,int b){
  int temp;
  if(a>b)return b;
  if(a<=b)return a;
}


int main(){

  int n,m,x;
  scanf("%d%d%d",&n,&m,&x);

  int c[n];

  rep(i,n){
    scanf("%d",&c[i]);
    rep(j,m) scanf("%d",&a[i][j]);
  }

  int result;
  int ans = 1001001001;
  int d[m];
  for(int bit=0; bit<(1<<n); bit++){
    int cost = 0;
    rep(i,m) d[i]=0;
    for(int i=0; i<n; i++){
      if((bit>>i)&1){
        cost += c[i];
        for(int j=0; j<m; j++){
            d[j] += a[i][j];
            //printf("%d ",d[j]);
        }
        //printf("\n");
      }

      result = 1;
      for(int j=0; j<m; j++){
        if(d[j]<x) result = 0;
      }
      if(result){
        ans = min(ans,cost);
      }
    }
  }
  
  if(ans == 1001001001){
    printf("-1");
  }else{
    printf("%d",ans);
  }

  return 0;
}
