#include<stdio.h>
int main(void){
  int R,G,B,N,i,t,ans;
  ans=0;
  scanf("%d %d %d %d",&R,&G,&B,&N);
  for(i=0;i<=N/R;i++){
    for(t=0;t<=(N-R*i)/G;t++){
      if((N-R*i-G*t)%B==0){ans=ans+1;}
    }
  }
  printf("%d",ans);
  return 0;
}
