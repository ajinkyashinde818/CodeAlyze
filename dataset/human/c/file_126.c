#include<stdio.h>
int main(void){
  int R,G,B,N;
  int r,g,ans=0;
  scanf("%d %d %d %d",&R,&G,&B,&N);
  for(r=0;r<=N/R;r++){
    for(g=0;g<=(N-R*r)/G;g++){
      if((N-R*r-G*g)%B==0){
        ans+=1;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
