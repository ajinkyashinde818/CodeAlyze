#include<stdio.h>

int main(){
  int n;
  int a[20],b[20],c[20];
  int sum = 0;
  scanf("%d",&n);
  for(int i = 0;i < n;i++){
    scanf("%d",a+i);
  }
  for(int i = 0;i < n;i++){
    scanf("%d",b+i);
  }
  for(int i = 0;i < n-1;i++){
    scanf("%d",c+i);
  }
  for(int i = 0;i < n-1;i++){
    sum += b[i];
    if(a[i] +1 == a[i+1]){sum += c[a[i]-1];}
  }
  sum += b[n-1];
  printf("%d\n",sum);
  return 0;
}
