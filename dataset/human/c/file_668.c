#include <stdio.h>
#define rep(i,n)for(int i=0;i<n;i++)
int main(){
  int n,m,a[51][51],b[51][51],f;
  char s[51];
  scanf("%d%d",&n,&m);
  rep(i,n){
    scanf("%s",s);
    rep(j,n)a[i][j]=(s[j]=='#'?1:0);
  }
  rep(i,m){
    scanf("%s",s);
    rep(j,m)b[i][j]=(s[j]=='#'?1:0);
  }
  
  rep(i,n+1-m)rep(j,n+1-m){
    f=1;
    rep(k,m)rep(l,m)if(b[k][l]^a[k+i][l+j])f=0;
    if(f){printf("Yes");return 0;}
  }
  printf("No");
  return 0;
}
