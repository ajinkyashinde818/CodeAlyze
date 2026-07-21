#include<stdio.h>
int main()
{
  int k,s;
  scanf("%d%d",&k,&s);
  
  int count=0;
  
  for(int x=0;x<=k;x++){
    for(int y=0;y<=k;y++){
      int z=s-x-y;
      if(z>=0&&z<=k)count+=1;
    }
  }
  
  printf("%d",count);
  
  return 0;
}
