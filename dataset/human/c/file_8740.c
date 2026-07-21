#include<stdio.h>

int main()
{
  int n;
  int a[100001],b[100001];
  int i,ans;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<100001;i++){
    b[i]=0;
  }
  ans=0;
  i=0;
  while(1){
    i=a[i]-1;
    ans++;
    if(i==1){
      printf("%d",ans);
      return 0;
    }
    if(b[i]==1){
      printf("%d",-1);
      return 0;
    }
    else{
      b[i]++;
    }
  }
}
