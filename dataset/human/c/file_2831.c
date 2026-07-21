#include<stdio.h>
int main(){
  int i,j,c=0,n,m;
  scanf("%d %d",&n,&m);
  for(i=0;i<=n;i++){
    for(j=0;j<=n;j++){
      if(i+j<=m&&i+j+n>=m)c++;
    }
  }
  printf("%d\n",c);
  return 0;
}
