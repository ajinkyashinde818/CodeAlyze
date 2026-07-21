#include<stdio.h>
int main(void)
{
  int n,d,x;
  int a[110];
  scanf("%d %d %d",&n,&d,&x);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  int sum=n;
  for(int i=0;i<n;i++){
    int start=1;
    while(start+a[i]<=d){
      sum++;
      start+=a[i];
    }
  }

  printf("%d\n",sum+x);
  return 0;
}
