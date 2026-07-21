#include<stdio.h>
int main(){
  int r,g,b,n,i,j,c=0;
  scanf("%d %d %d %d",&r,&g,&b,&n);
  for(i=0;i<=n;i++){
    if(i*r>n)continue;
    for(j=0;j<=n;j++){
      if(i*r+j*g>n)continue;
      if((n-i*r-j*g)%b==0)c++;
    }
  }
  printf("%d\n",c);
  return 0;
}
