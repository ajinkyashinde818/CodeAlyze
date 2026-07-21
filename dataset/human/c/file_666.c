#include <stdio.h>
int main(void){
  int n,m,i,j,k,l;
  char a[51][51],b[51][51];
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++) scanf("%s",a[i]);
  for(i=0;i<m;i++) scanf("%s",b[i]);
  for(i=0;i<n-m+1;i++){
    for(j=0;j<n-m+1;j++){
      int match=1;
      for(k=0;k<m;k++){
        for(l=0;l<m;l++){
          if(a[i+k][j+l]!=b[k][l]){match=0;break;}
        }
      }
      if(match==1) {printf("Yes");return 0;}
    }
  }
  printf("No");
  return 0;
}
