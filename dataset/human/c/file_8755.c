#include<stdio.h>
int main(){
  int n,i;
  scanf("%d",&n);
  int a[n+1][2];
  for(i=1;i<=n;i++){
    scanf("%d",&a[i][0]);
    a[i][1]=0;
  }
  i=1;
  int count=0;
  while(i!=2 && a[i][1]==0){
    a[i][1]++;
    i=a[i][0];
    count++;
  }
  if(i==2)
    printf("%d\n",count);
  else
    puts("-1");
  return 0;
}
