#include <stdio.h>
int main(){
  int i,j,n,maxv,minv;
  int input[200000];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&input[i]);
  }

  maxv = input[1]-input[0];
  minv = input[0];
  for(i=1;i<n;i++){
    if( maxv<input[i]-minv ) maxv = input[i]-minv;
    if( input[i]<minv ) minv = input[i];
  }

  printf("%d",maxv);
  printf("\n");
  return 0;
}
