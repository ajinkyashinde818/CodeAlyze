#include<stdio.h>
int main(){
  int n,i,count=0,score;
  scanf("%d",&n);
  int a[n+1],c[n+1];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++){
    scanf("%d",&score);
    count+=score;
  }
  for(i=0;i<n-1;i++)
    scanf("%d",&c[i]);
  for(i=0;i<n-1;i++){
    if(a[i]==a[i+1]-1)
      count+=c[a[i]-1];
  }
  printf("%d\n",count);
  return 0;
}
