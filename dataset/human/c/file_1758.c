#include<stdio.h>
int main(){
  int i,n;
  scanf("%d",&n);
  int a[n+10],b[n+10],c[n+10];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=0;i<n;i++)
    scanf("%d",&b[i]);
  for(i=0;i<n-1;i++)
    scanf("%d",&c[i]);

  int sum=0;
  for(i=0;i<n;i++){
    sum += b[a[i]-1];
    if(i==0)
      continue;
    else{
      if(a[i-1]==a[i]-1)
        sum += c[a[i-1]-1];
    }
  }
  printf("%d",sum);
  return 0;
}
