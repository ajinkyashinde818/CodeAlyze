#include<stdio.h>
int main(void)
{
  int a,b,k,x,tmp,i,d[100];
  scanf("%d%d%d",&a,&b,&k);
  if(1 > a){
    printf("エラー\n");
    return 1;
  }else if(b > 100){
    printf("エラー\n");
    return 1;
  }

  if(a<b){
    tmp=a;
    a=b;
    b=tmp;
  }

  for(i=1;i<=a;i++){
    if(a%i == 0 && b%i == 0){
      x++;
      d[x] = i;
    }
  }

  printf("%d\n",d[x-k+1]);


  return 0;
}
