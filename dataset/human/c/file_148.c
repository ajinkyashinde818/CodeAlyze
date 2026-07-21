#include<stdio.h>
int main(){
  int r,g,b,n,count=0;
  int i,j;
  scanf("%d %d %d %d",&r,&g,&b,&n);
  for(i=0;i<=n/r;i++){
    for(j=0;j<=(n-r*i)/g;j++){
      if((n-r*i-g*j)%b==0)
        	count++;
    }
  }
  printf("%d\n",count);
  return 0;
}
