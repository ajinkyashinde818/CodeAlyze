#include<stdio.h>
#include <string.h>
int main(void)
{
  int D1[100],D2[100],i=0,N,cnt=0,ans=0;
  
  scanf("%d",&N);
  for(i;i<N;i++)
  {
    scanf("%d %d",&D1[i],&D2[i]);
    if(D1[i]==D2[i]){
      cnt++;
      if(cnt>=3){ans=1;}
    }else{
      cnt=0;
    }
  }
  
  if(ans==1){
    printf("Yes");
  }else{
    printf("No");
  }
  
  return 0;
}
