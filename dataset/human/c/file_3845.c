#include <stdio.h>

int max(int p0,int p1){
  return(p0>p1?p0:p1);
}
int main(){
  long a,m;
  int i,j,l[2][100000],np,p[100000];
  p[0]=2;
  np=1;
  for(i=3;i<100000;i+=2){
    for(j=1;j<np;j++){
      if(i%p[j]==0) break;
    }
    if(j==np){
      p[np]=i;
      np++;
    }
  }
  for(i=0;i<2;i++){
    scanf("%ld",&a);
    for(j=0;j<np;j++){
      l[i][j]=0;
      while(a%p[j]==0){
        a/=p[j];
        l[i][j]++;
      }
    }
  }
  m=1;
  for(i=0;i<np;i++){
    for(j=max(l[0][i],l[1][i]);j>0;j--){
      m*=(long)p[i];
    }
  }
  printf("%ld",m);
  return(0);
}
