#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
  int n, m,i,j,k,l;
  scanf("%d%d",&n,&m);
  char a[55][55],b[55][55];
  for(i=0;i<n;i++){
    scanf("%s",a[i]);
  }
  for(i=0;i<m;i++){
    scanf("%s",b[i]);
  }
  for(i=0;i<n-m+1;i++){
    for(j=0;j<n-m+1;j++){
      int t=1;
      for(k=0;k<m;k++){
        for(l=0;l<m;l++){
          if(a[i+k][j+l]!=b[k][l])t=0;
        }
      }
      if(t){
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");
}
