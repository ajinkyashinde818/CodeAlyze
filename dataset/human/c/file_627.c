#include<stdio.h>

int main(void)
{
  int n,m;
  char a[100][100];
  char b[100][100];
  int i,j,k,l,s=0,q=0;

  scanf("%d %d",&n,&m);

  for(i=0;i<n;i++)
    scanf("%s",a[i]);

  for(i=0;i<m;i++)
    scanf("%s",b[i]);

  for(i=0;i<=n-m;i++){
    for(l=0;l<=n-m;l++){
    s=0;
    for(j=0;j<m;j++){
      for(k=0;k<m;k++){
      if(a[k+i][j+l]==b[k][j])
        s++;
      }
    }
    if(s==m*m){
      q=1; break;
    }
  }
}
  if(q==1)
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}
