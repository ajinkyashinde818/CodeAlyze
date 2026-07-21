#include<stdio.h>

int main(){
  int m = 0;
  int n = 0;
  char a[100][100] = {};
  char b[100][100] = {};
  int i = 0;
  int j = 0;
  int k = 0;
  int l = 0;
  int flag = 0;
  int success = 0;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++){
    scanf(" %s",a[i]);
  }
  //
  for(i=0;i<m;i++){
    scanf(" %s",b[i]);
  }
  //
  for(i=0;i+m<=n;i++){
    for(j=0;j+m<=n;j++){
      flag = 1;
      for(k=0;k<m;k++){
        for(l=0;l<m;l++){
          if(b[k][l] != a[i+k][j+l]){
            flag = 0;
          }
        }
      }
      if(flag){
        success = 1;
      }
    }
  }
  if(success){
    printf("Yes");
  }else{
    printf("No");
  }
  return 0;
}
