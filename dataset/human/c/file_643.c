#include<stdio.h>
int main(){
  int n,m,i,j,k,l;
  scanf("%d%d",&n,&m);
  char a[n+1][n+1],b[m+1][m+1];
  for(i=0;i<n;i++)
    scanf("%*c%s",a[i]);
  for(i=0;i<m;i++)
    scanf("%*c%s",b[i]);
  for(i=0;i<=n-m;i++){
    for(j=0;j<=n-m;j++){
      int check=0;
      for(k=0;k<m;k++){
        for(l=0;l<m;l++){
          if(a[i+k][j+l]!=b[k][l])
            check=1;
        }
      }
      if(check==0){
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");
  return 0;
}
