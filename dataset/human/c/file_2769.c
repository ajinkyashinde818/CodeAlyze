#include<stdio.h>
int main()
{
  int K,S;
  int X,Y,Z;
  int con=0;
  
  scanf("%d %d",&K,&S);
  
  for(int i=0;i<=K;i++){
    for(int j=0;j<=K;j++){
      X=i;
      Y=j;
      Z=S-X-Y;
      if(Z<=K&&Z>=0) con++;
    }
  }
  printf("%d",con);
  
  return 0;
}
