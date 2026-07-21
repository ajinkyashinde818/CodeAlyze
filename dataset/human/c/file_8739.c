#include<stdio.h>

int main(){
  int n,a[100000],i,visit[100001]={},cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  i=1;
  while(i!=2){
    visit[i]++;
    if(visit[i]>1){
      printf("-1\n");
      return 0;
    }
    i=a[i-1];
    cnt++;
  }
  printf("%d\n",cnt);
}
