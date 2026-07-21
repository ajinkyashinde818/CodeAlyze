#include<stdio.h>
int main(){
  int n,d[100010][2],f,i;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d %d",&d[i][0],&d[i][1]);
  f=0;
  for(i=2;i<n;i++){
    if(d[i-2][0]==d[i-2][1]&&d[i-1][0]==d[i-1][1]&&d[i][0]==d[i][1])f=1;
  }
  printf("%s\n",f?"Yes":"No");
  return 0;
}
