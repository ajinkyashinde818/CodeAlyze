#include<stdio.h>

int main(){
  int N,D1,D2,counter=0,ans=0;
  scanf("%d",&N);
  for (int i = 0; i < N; i++)
  {
    scanf("%d%d",&D1,&D2);
    if (D1==D2)
    {
      counter++;
      if (counter>=3)
      {
        ans=1;
      }
    }else{
      counter=0;
    }
    
    
  }
  
  ans > 0 ? puts("Yes"): puts("No"); 

  return 0;
}
