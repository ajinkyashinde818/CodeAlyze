#include <stdio.h>
int main(void){
  int n,m,a[200000],e[100000],f[200001]={0},i;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)
    a[i]=i+1;
  for(i=0;i<m;i++)
    scanf("%d",&e[i]);
  for(i=m-1;i>=0;i--){
    if(f[e[i]])
      continue;
    printf("%d\n",e[i]);
    f[e[i]]++;
  }
  for(i=0;i<n;i++){
    if(f[a[i]])
      continue;
    printf("%d\n",a[i]);
  }
  return 0;
}
