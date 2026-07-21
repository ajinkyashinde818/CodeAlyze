#include <stdio.h>

int main(){
  int a[20],b[20],c[20];
  int n,s=0;

  scanf("%d",&n);
  
  for (int i = 1;i <= n;i++){
    scanf("%d",&a[i]);
  }
  for (int i = 1;i <= n;i++){
    scanf("%d",&b[i]);
  }
  for (int i = 1;i <= n - 1;i++){
    scanf("%d",&c[i]);
  }
  for(int i = 1;i <= n;i++){
    if (a[i+1]-a[i] == 1){
      s+=b[a[i]] + c[a[i]];
    }else{
      s+=b[a[i]];
    }
  }
  printf("%d",s);
  return 0;
}
