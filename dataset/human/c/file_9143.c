#include<stdio.h>
int main(){
  int n;
  int k;
  scanf("%d%d",&n,&k);
  int a[n];
  int count=0;
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(k<=a[i])
      count++;
  }
  printf("%d",count);
}
