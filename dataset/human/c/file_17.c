#include <stdio.h>
int main(){
  int R,G,B,N,i,j,m,ans=0;
  scanf("%d%d%d%d",&R,&G,&B,&N);
  for(i=0;i<=N/R;i++){
    m=N-R*i;
    for(j=0;j<=m/G;j++)
    if((m-G*j)%B==0)ans++;
  }
  printf("%d\n",ans);
  return 0;
}
