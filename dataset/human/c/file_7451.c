#include<stdio.h>

int main(){
  int a[20000],i=0,j=0,b;
  while(i>=0){
    scanf("%d",&a[i]);
    if(a[i]==0){
      b=i-1;
      i=-2;
    }
    if(a[i]!=0)i++;
  }
  for(j=0;j<b+1;j++){
    printf("Case %d: %d\n",j+1,a[j]);
  }
  return 0;
}
