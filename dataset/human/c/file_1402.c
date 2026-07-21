#include<stdio.h>
int main(){
  int n,m,i,j;
  scanf("%d %d",&n,&m);
  int a[m][2],b[n+1];
  for(i=0;i<n+1;i++)
    b[i]=0;
  for(i=0;i<m;i++)
   scanf("%d %d",&a[i][0],&a[i][1]);
  for(i=0;i<m;i++)
    if(a[i][1]==n)
      b[a[i][0]]=1;
  for(i=0;i<m;i++)
    if(a[i][0]==1 && b[a[i][1]]==1){
      printf("POSSIBLE\n");
      return 0;
    }
  printf("IMPOSSIBLE\n");
}
