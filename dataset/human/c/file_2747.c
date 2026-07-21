#include <stdio.h>

int main(){

  int k,s,i,j,l,count=0;

  scanf("%d %d",&k,&s);

  for(i=0;i<=k;i++){
    for(j=0;j<=k;j++){
      if(i+j>s) break;
      l=s-i-j;
      if(l<=k) count++;
    }
  }
  printf("%d\n",count);
  return 0;
}
