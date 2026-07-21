#include <stdio.h>
int main(){
  int c=0;
  int k,s,l;
  scanf("%d %d",&k,&s);
  for(int i=0;i<=k;i++){
    for(int j=0;j<=k;j++){
      l=s-i-j;
      if(l>=0&&l<=k) c++;
    }
  }
  printf("%d",c);
  return 0;
}
