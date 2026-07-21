#include<stdio.h>

int main()
{
  int k,s;
  int x,y,z;
  int t=0;
  scanf("%d%d",&k,&s);
  for(x=0;x<=k;x++){
    for(y=0;y<=k;y++){
      if(0<=s-x-y && s-x-y<=k) t++;
    }
  }
  printf("%d\n",t);
  return 0;
}
