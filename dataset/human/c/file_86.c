#include<stdio.h>

int main(){
  int a,b,c,N,i,j,sum=0;
  scanf("%d %d %d %d",&a,&b,&c,&N);
  for(i = 0;i <= N/a;i++){
    for(j = 0;j <= (N-i*a)/b;j++){
      if((N-i*a-j*b)%c == 0){sum++;}
    }
  }printf("%d\n",sum);
  return 0;
}
