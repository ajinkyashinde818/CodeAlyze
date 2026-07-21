#include<stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  int ai=0,c=1;
  for(int i=0;i<n;i++){
    if(a[ai]==2){
      printf("%d",c);
      return 0;
    }
    ai = a[ai] - 1;
    c++;
  }
  printf("-1");
}
