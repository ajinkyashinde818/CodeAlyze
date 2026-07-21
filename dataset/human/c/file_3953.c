#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
int main(){
  int a,b,k,i=0,j,d[1000];
  scanf("%d%d%d",&a,&b,&k);
  for(j=1;j<=min(a,b);j++){
    if(a%j==0&&b%j==0){
      d[i]=j;
      i++;
    }
  }
  printf("%d",d[i-k]);
}
