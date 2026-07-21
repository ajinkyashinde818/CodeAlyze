#include<stdio.h>
int main(){
  int z;
  int i,j;
  int k,s;
  int ans=0;
  scanf("%d %d",&k,&s);
  for(i=0;i<=k;i++){
    for(j=0;j<=k;j++){
      z=s-i-j;
      if(z>=0&&z<=k)ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
}
