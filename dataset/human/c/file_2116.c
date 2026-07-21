#include<stdio.h>
#include<math.h>
int main(void)
{
  long int n,i,j,a,b,c,p,d;
  scanf("%ld",&n);
  if(n%2==1){
    printf("0\n");
  }
  a=0;
  if(n%2==0){
    b=n;
    p=1;
    while(p*10<=n){
      d=b-(b%(10*p));
      a=a+(d/(10*p));
      /*printf("%ld\t",a);*/
      p=p*5;
      /*printf("%ld\n",p*10);*/
    }
  printf("%ld\n",a);
  }
  return 0;
}
