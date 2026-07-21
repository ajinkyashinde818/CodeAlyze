#include <stdio.h>

//Compiler version gcc  6.3.0

int main()
{
  int k,s;
  int ans=0;
  scanf("%d %d",&k,&s);
  
  for(int x=0;x<=k;x++){
    for(int y=0;y<=k;y++){
      int temp = s -x - y;
      
     if(0<= temp && temp <= k)
       ans++;
      }
      
    }
  
   printf("%d",ans);
  
  
  
  return 0;
}
