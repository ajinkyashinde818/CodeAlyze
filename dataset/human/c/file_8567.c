#include <stdio.h>

int main(){
  int n,i,look,x=0;
  int a[100001];
    int b[100001];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    b[i]=0;
  }
  look = 1;
  for(i=0;i<n;i++){
    look = a[look-1];
    if(look==2){
      x = 1;
      break;
    }
  }
  if(x==1){
    printf("%d\n",i+1);
  }else{
    printf("%d\n",-1);
  }
  return 0;
}
