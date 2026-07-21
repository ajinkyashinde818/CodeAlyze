#include<stdio.h>

main(){
  int R,G,B,N;
  scanf("%d%d%d%d",&R,&G,&B,&N);
  int ans=0;
  for(int i=0;i<=N/R;i++){
    for(int j=0;j<=N/G;j++){
      if(((N-i*R-j*G)%B==0)&&(N-i*R-j*G>=B||N-i*R-j*G==0))ans++;
    };
  };
  
  printf("%d",ans);
  return 0;
}
