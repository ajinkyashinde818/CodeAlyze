#include<stdio.h>
int MAX(int a,int b){return a<b?b:a;}
int main(){
  int n,m,a,i,d[200010];
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++)scanf("%d",&d[i]);
  a=d[0]+n-d[m-1];
  for(i=1;i<m;i++)a=MAX(a,d[i]-d[i-1]);
  printf("%d\n",n-a);
  return 0;
}
